/*
 * 题意：
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的绝对值最大为 k。
 *
 * 思路：
 * 使用 set 维护一个长度为 k 的滑动窗口
 * 遍历整数数组
 * 1. 当 set 中存在当前数的时候，说明发现了重复元素，直接返回 true
 * 2. 当 set 中不存在当前数的时候，将当前数插入到 set 中（相当于滑动窗口的右指针右移）
 * 然后判断 set 的大小，如果 set 的 size 大于 k 就表明当前滑动窗口已经超过了 k，应该将最早加入的那个元素删除（相当于滑动窗口的左指针右移）
 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); ++i) {
        if (s.count(nums[i]) == 0) {
            s.insert(nums[i]);
            if (s.size() > k) {
                s.erase(nums[i-k]);
            }
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,1,2,3};
    int k = 2;
    auto ret = containsNearbyDuplicate(nums, k);
    cout << ret << " ";
    return 0;
}
