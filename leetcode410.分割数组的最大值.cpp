/*
 * 题意：
 * 给定一个非负整数数组和一个整数 m，你需要将这个数组分成 m 个非空的连续子数组。
 * 设计一个算法使得这 m 个子数组各自和的最大值最小。
 * 
 * 输入: nums = [7,2,5,10,8]  m = 2
 * 输出: 18
 * 解释:
 * 一共有四种方法将nums分割为2个子数组。其中最好的方式是将其分为[7,2,5] 和 [10,8]
 * 因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
 *
 * 思路：
 * 1. 暴力法————时间复杂度O(n^m)
 * 找到所有的分割方案，更新全局最小值
 * 
 * 2. 二分搜索法————时间复杂度O(n*logn)
 * 子数组和的最大值有两个边界：
 * 如果将所有的数分到一个组，子数组的最大和就是整个数组的和
 * 如果将所有的数单独分为一组，子数组的最大和就是数组中最大的元素
 * 
 * 题目所求的最大和肯定在这个区间之内
 * 所以只需要对这个区间之内的值 mid 进行二分查找，每次将数组划分成和不超过 mid 的子数组 
 * 如果子数组个数 cnt 大于 m， 说明mid较小，导致分的组较多，应该将二分查找的左区间 设置为 mid + 1
 * 如果子数组个数 cnt 小于等于 m， 说明mid较大(或者正好是目标值)，导致分的组较少，应该将二分查找的右区间 设置为 mid
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int splitArray(vector<int>& nums, int m) {
    // left right 分别为子数组和最大值的左边界和右边界
    long long left = nums[0], right = 0;
    for (auto num : nums) {
        right += num;
        left = num > left ? num : left;
    }

    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long temp = 0;
        // cnt设置为1表明至少存在一种分法
        int cnt = 1;
        for (auto num : nums) {
            temp += num;
            if (temp > mid) {
                temp = num;
                cnt++;
            }
        }
        if (cnt > m) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}



int main() {
    vector<int> nums = {7,2,5,10,8};
    int m = 2;
    auto ret = splitArray(nums, m); // 18
    cout << ret << " ";

    return 0;
}