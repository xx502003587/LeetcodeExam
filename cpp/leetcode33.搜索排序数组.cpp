/*
 * 题意：
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 你可以假设数组中不存在重复的元素。
 * 你的算法时间复杂度必须是 O(log n) 级别。
 *
 * 思路：
 * 局部有序，可以使用二分查找
 * 算法基于一个事实，数组从任意位置劈开后，至少有一半是有序的，什么意思呢？
 * 比如 [ 4 5 6 7 1 2 3] ，从 7 劈开，左边是 [ 4 5 6 7] 右边是 [ 7 1 2 3]，左边是有序的。
 * 基于这个事实。
 * 我们可以先找到哪一段是有序的 (只要判断端点即可)，然后看 target 在不在这一段里，如果在，那么就把另一半丢弃。如果不在，那么就把这一段丢弃。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int search(vector<int> &nums, int target) {
    if (nums.empty()) {
        return -1;
    }
    int begin = 0;
    int end = nums.size() - 1;
    while (begin <= end) {
        int mid = begin + (end - begin) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        //递增数列在数组的前一半
        if (nums[begin] <= nums[mid]) {
            // target 在这段里
            if (target >= nums[begin] && target < nums[mid]) {
                end = mid - 1;
            } else {
                begin = mid + 1;
            }
        }
        //递增数列在数组的后一半
        else {
            // target 在这段里
            if (nums[mid] < target && target <= nums[end]) {
                begin = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 0);
    return 0;
}
