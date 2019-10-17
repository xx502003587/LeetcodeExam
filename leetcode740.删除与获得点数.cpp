/*
 * 题意：
 * 给定一个整数数组 nums ，你可以对它进行一些操作。
 * 每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。
 * 之后，你必须删除每个等于 nums[i] - 1 或 nums[i] + 1 的元素。
 * 开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
 * 每个整数nums[i]的大小都在[1, 10000]范围内。
 *
 * 思路：
 * 根据题目要求，如果要获得 nums[i] 的点数，那就必须删除 nums[i] 左边和右边相邻的值
 * 那么要在两种情况中做抉择：
 * 1. 不删，直到前一个数为止得到的分数就是当前的分数
 * 2. 删，前后两个数无法再被使用
 * 
 * 思路与 leetcode198.打家劫舍 有些类似，即：如果选择了当前位置，前后相邻的位置就不能再被选择
 * 
 * 于是，首先找出 nums 中最大的元素 max_value，然后维护一个长度为 max_value+1 的数组 all
 * 其中 all[i] 表示 i 在 nums 中出现的次数
 * 
 * 令 dp[i] 表示到第 i 位置为止获得的最大分数
 * 那么递推公式为： dp[i] = max(dp[i-1], dp[i-2]+i*all[i])
 * 解释为：
 * 1. 如果不删除 nums[i]，那么可以获得的最大分数就是前一个位置的最大分数 dp[i-1]
 * 2. 如果删除 nums[i]，那么可以获得的最大分数就是前两个位置的最大分数加上当前位置的数乘以当前位置数出现的次数
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int deleteAndEarn(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    } else if (nums.size() == 1) {
        return nums[0];
    }

    int max_value = *max_element(nums.begin(), nums.end());
    vector<int> all(max_value+1, 0);
    for (auto num : nums) {
        all[num]++;
    }
    vector<int> dp(max_value+1, 0);
    dp[1] = all[1];
    dp[2] = max(dp[1], all[2]*2);
    for (int i = 2; i <= max_value; ++i) {
        dp[i] = max(dp[i-1], dp[i-2] + i*all[i]);
    }
    return dp[max_value];
}

int main() {
    vector<int> nums = {3, 4, 2};
    cout << deleteAndEarn(nums);
    return 0;
}