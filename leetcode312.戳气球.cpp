/*
 * 题意：
 * 有 n 个气球，编号为0 到 n-1，每个气球上都标有一个数字，这些数字存在数组 nums 中。
 * 现在要求你戳破所有的气球。
 * 每当你戳破一个气球 i 时，你可以获得 nums[left] * nums[i] * nums[right] 个硬币。 
 * 这里的 left 和 right 代表和 i 相邻的两个气球的序号。
 * 注意当你戳破了气球 i 后，气球 left 和气球 right 就变成了相邻的气球。
 * 求所能获得硬币的最大数量。
 *
 * 思路：
 * 动态规划
 * 令dp[i][j]表示戳破 [i+1...j-1] 号气球的最大收益
 * 假设 k 号气球（i+1 <= k <= j-1）是 [i+1...j-1] 中最后一个被戳破的，则递推公式为
 * dp[i][j] = max {for k = range(i+1, j-1) nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]}
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCoins(vector<int>& nums) {
    int n = nums.size() + 2;
    // 在数组前后各插入一个1，为了方便边界计算
    nums.insert(nums.begin(),1);
    nums.push_back(1);
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // k 是区间长度
    for (int k = 2; k < n; ++k) {
        // i 是区间左端点
        for (int i = 0; i < n - k; ++i) {
            // j 是区间右端点
            int j = i + k;
            // l 是当前区间最后一个戳破时
            for (int l = i+1; l < j; ++l) {
                dp[i][j] = max(dp[i][j], nums[i]*nums[l]*nums[j]+dp[i][l]+dp[l][j]);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    vector<int> nums = {3,1,5,8};
    auto ret = maxCoins(nums);
    cout << ret << endl; // 167，戳的顺序为1(得分1*3*5=15) 5(得分3*5*8=120) 3(得分3*8=24) 8(得分8)
    return 0;
}

