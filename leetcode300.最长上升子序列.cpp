/*
 * 题意：
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 *
 * 思路：
 * 动态规划
 * 令 dp[i] 表示到第 i 个数为止最长的递增子序列的长度
 * 那么递推公式为 dp[i] = max(dp[i], dp[j] + 1)，其中j < i
 * 公式可以理解为：到 nums[i] 为止，最长的递增子序列的长度应该是在 nums[i] 之前且比 nums[i] 小的最长递增子序列的长度+1
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    int res = 1;
    for (int i = 1; i < nums.size(); ++i) {
        // 找到 nums[i] 之前的元素中比 nums[i] 小的最大 dp[j]
        for (int j = 0; j < i; ++j) {  
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return dp;
}

vector<int> generateLIS(vector<int> &arr, vector<int> &dp) {
    int len = 0;
    int index = 0;
    //寻最长递增子序列末尾的位置和值
    for (int i = 0; i < dp.size(); i++) {
        if (dp[i] > len) {
            len = dp[i]; // 最长序列长度
            index = i; // 最长序列末位置
        }
    }
    vector<int> lis(len, 0);
    lis[--len] = arr[index];
    for (int i = index; i >= 0; i--) {
        if (arr[i] < arr[index] && dp[i] == dp[index] - 1) {
            //从后往前找子序列
            lis[--len] = arr[i];
            index = i;
        }
    }
    return lis;
}

int main() {
    vector<int> nums = {1, 3, 9, 2, 6};
    auto dp = lengthOfLIS(nums);
    auto res = generateLIS(nums, dp);
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}
