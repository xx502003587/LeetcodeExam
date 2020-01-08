/*
 * 题意：
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。
 * 找出给定目标值在数组中的开始位置和结束位置。
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 如果数组中不存在目标值，返回 [-1, -1]。
 *
 * 思路：
 * 二分查找
 * 分成两步：寻找左端点 和 寻找右端点
 * 1. 寻找左端点
 * 当 nums[mid] >= target 时，表明 mid 的左侧还可能有 target，所以令 high = mid 在左半部分中进行查找
 * 当 nums[mid] < target 时，表明 target 在 mid 的右侧，所以令 low = mid + 1 在右半部分中进行查找
 * 当查找到不满足 low < high 条件时表明 low == high，此时指向的值有两种情况：
 * 如果 nums 中存在 target，那么 mid 就是 target 在数组中的开始位置
 * 如果 nums 中不存在 target，那么 mid 就是比 target 大的第一个数的下标
 *
 * 2. 寻找右端点
 * 当 nums[mid] <= target 时，表明 mid 的右侧还可能有 target，所以令 low = mid + 1 在右半部分中进行查找
 * 当 nums[mid] > target 时，表明 target 在 mid 的左侧，所以令 high = mid 在左半部分中进行查找
 * 当查找到不满足 low < high 条件时表明 low == high
 * 由于每当存在 nums[mid] <= target时都把 low 指向 mid 的下一个，所以当 low == high 时指向的值为大于 target 的第一个数
 *
 * 首先寻找左端点，然后对左端点返回的 left 值进行判断
 * 如果 left 大于等于 nums 的长度 或者 left 所指向的值不等于 target，就表明 nums 中不存在等于 target 的值，直接返回{-1,-1}即可
 * 不符合上述条件时，再寻找右端点，将左右端点索引返回
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int searchLeft(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size();
    int mid = 0;
    while (low < high) {
        mid = low + ((high-low) >> 1);
        if (target == nums[mid]) {
            high = mid;
        } else if (target > nums[mid]) {
            low = mid + 1;
        } else if (target < nums[mid]) {
            high = mid;
        }
    }
    return low;
}

int searchRight(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size();
    int mid = 0;
    while (low < high) {
        mid = low + ((high-low) >> 1);
        if (target == nums[mid]) {
            low = mid + 1;
        } else if (target > nums[mid]) {
            low = mid + 1;
        } else if (target < nums[mid]) {
            high = mid;
        }
    }
    return low - 1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> ret = {-1,-1};
    if (nums.empty()) {
        return ret;
    }
    int left = searchLeft(nums, target);
    // 如果 left 大于等于数组的长度，或者 left 指向的值不等于 target 表明数组中不存在值等于 target 的数
    if (left >= nums.size() || nums[left] != target) {
        return ret;
    }
    ret[0] = left;
    ret[1] = searchRight(nums, target);
    return ret;
}

int main() {
    vector<int> nums = {2,2};
    auto ret = searchRange(nums, 3);
    for (auto num : ret) {
        cout << num << " ";
    }
    return 0;
}
