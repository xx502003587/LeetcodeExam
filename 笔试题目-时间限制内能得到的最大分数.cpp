/*
 * 题意：
 * 小明在做考试题目，一共有 n 道题目
 * 假设小明每一个题目都会做，但是时间有限，每个题需要花费的时间和得到的分数不同
 * 求小明在考试的有限时间内，能够得到的最高分是多少（每个题只能选择做或不做）
 *
 * 思路：
 * 0/1背包问题
 * 总时间 time ——背包能装下的总重量
 * 每个题的分数 score ——物品的价值
 * 每个题的耗时 cost ——物品的重量
 * 
 * 动态规划：
 * 令 dp[i][j] 表示前 i 个题，在 j 的有限时间内能得到的最高分
 * 递推公式为 dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]]+score[i])
 * 解释：
 * dp[i][j]表示前 i 个题，在 j 的有限时间内能得到的最高分
 * 对于第 i 个题来说，有两种情况
 * 1. 如果不做第 i 个题，能够获得的最大分数为 dp[i-1][j]，即前 i-1 个题在 j 时间内能获得的最大分数
 * 2. 如果做第 i 个题，能够获得的最大分数为 dp[i-1][j-cost[i]]+score[i]，即前 i-1 个题在 j-cost[i] 的时间得到的最高分 加上当前题目的得分
 * dp[n][time] 就是 n 个题目在 time 时间限制内能得到的最大分数
 * 空间复杂度为 O(n*time)
 * 
 * 求题目组合：
 * 以上方法只能得到最后获得的最大分数，并无法得到获得这个分数的题目组合情况
 * 根据 dp 数组进行组合求解，对于 dp[i][j] 来说
 * 1. 如果 dp[i][j] == dp[i-1][j]，说明第 i 个题目没有做，那么就回到 dp[i-1][j] 进行判断
 * 2. 如果 dp[i][j] != dp[i-1][j]，且 j - cost[i] >= 0 && dp[i][j] == dp[i-1][j-cost[i]]+score[i]，就说明第 i 个题目做了，那么就继续回到 dp[i-1][j-cost[i]] 进行判断
 * 维护一个数组，对每个题目进行判断，便可输出最后的题目组合
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> compute(int n, vector<int>& score, vector<int>& cost, int time) {
    vector<vector<int>> dp(n + 1, vector<int>(time + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= time; ++j) {
            if (cost[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + score[i]);
            }
        }
    }
    return dp;
}

void traceback(const vector<vector<int>>& dp, const vector<int>& score, const vector<int>& cost,
               int i, int j, vector<bool>& flag) {
    if (i >= 1) {
        if (dp[i][j] == dp[i-1][j]) {
            flag[i] = false;
            traceback(dp, score, cost, i-1, j, flag);
        } else if (j - cost[i] >= 0 && dp[i][j] == dp[i-1][j-cost[i]]+score[i]) {
            flag[i] = true;
            traceback(dp, score, cost, i-1, j-cost[i], flag);
        }
    }
}

/*
 * 由于每一次更新dp数组时，只用到了 dp[i-1][0~time] 的信息
 * 所以可以将 dp 数组改成一维数组从而降低空间复杂度
 * 由于每次更新会用到dp[j-cost[i]]，所以数组应该从后往前进行更新，这样才可以保证每次更新时 dp[j-cost[i]] 是上一轮计算得到的
 */ 
vector<int> compute_optimize(int n, vector<int>& score, vector<int>& cost, int time) {
    vector<int> dp(time + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = time; j >= 0; --j) {
            if (j - cost[i] >= 0 && dp[j] <= dp[j-cost[i]]+score[i]) {
                dp[j] = max(dp[j], dp[j - cost[i]] + score[i]);
            }
        }
    }
    return dp;
}

int main() {
    int n = 5;
    vector<int> score = {0, 5, 4, 3, 5, 2};
    vector<int> cost = {0, 2, 2, 3, 5, 1};
    int time = 10;

    auto dp = compute(n, score, cost, time); // 16
    cout << "一共可以得到 " << dp[n][time] << " 分" << endl;
    vector<bool> flag(n+1, false);

    traceback(dp, score, cost, n, time, flag);
    for (int i = 1; i <= n; ++i) {
        if (flag[i]) {
            cout << "做第" << i << "题，耗时" << cost[i] << "，得分" << score[i] << endl;
        }
    }
    return 0;
}