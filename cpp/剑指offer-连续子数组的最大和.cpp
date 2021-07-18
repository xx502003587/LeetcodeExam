/*
 * 题意：
 * 给一个数组，返回它的最大连续子序列的和
 * 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
 *
 * 思路：
 * 动态规划法
 * 维护一个数组dp，令dp[i]表示到第i个数结尾的子数组的最大和
 * 考虑dp[i-1]，如果dp[i-1]为负数，那么就算dp[i-1]加上A[i]，得到的值也不可能比A[i]大，所以这种情况下dp[i] = A[i]
 * 如果dp[i-1] >= 0，那么dp[i]就等于dp[i-1]加上A[i]
 * 综上，dp[i] = max(dp[i-1]+A[i], A[i]) ，dp中最大的数就是要求的和
 */

#include <iostream>
#include <vector>

using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
    vector<int> dp(array.size(), 0);
    dp[0] = array[0];
    int max_num = array[0];
    for (int i = 1; i < array.size(); ++i) {
        dp[i] = max(array[i], array[i] + dp[i-1]);
        max_num = dp[i] > max_num ? dp[i] : max_num;
    }
    return max_num;
}

int main() {
    vector<int> input = {1,-2,3,10,-4,7,2,-5};
    auto ret = FindGreatestSumOfSubArray(input);
    cout << ret << endl;

    return 0;
}
