/*
 * 题意：
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 * 你最多可以完成 两笔 交易。设计一个算法来计算你所能获取的最大利润。
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 * 思路：
 * 限制条件为最多交易两次，使用动态规划的思路来做
 * 令dp[i][t]表示前 i 天，最多进行 t 次交易，获得的最大利润
 * 如果第 i 天不作任何操作，那么当天的最高利润就是前一天的最高利润，即dp[i][t] = dp[i-1][t]
 * 如果第 i 天要将股票卖出去，那么首先要在 0-i 天中挑选一天把股票买进来
 * 如果第 0 天买入，那么获得的利润是 price[i] - price[0]
 * 如果第 1 天买入，那么获得的利润是 price[i] - price[1] + dp[0][t-1]
 * 如果第 2 天买入，那么获得的利润是 price[i] - price[2] + dp[1][t-1]
 * 如果第 j 天买入，那么获得的利润是 price[i] - price[j] + dp[j-1][t-1]
 * 即：如果第 j 天买入，那么在 j-1 天已经获得了一个利润值，并且已经进行了 t-1 次交易，那么获得的利润就是 卖出价 - 买入价 + 买入之前已经获得的最大利润
 * 所以只需挑选出能够使获得利润最大的那一天，然后将利润值与不做任何操作时的利润值进行比较，即可得出第 i 天最多交易 t 次的最大利润
 * 递推公式：dp[i][t] = max(dp[i-1][t], max(price[i]-price[0],  price[i]-price[1]+dp[0][t-1],  ...  ,  price[i]-price[j]+dp[j-1][t-1]))
 * 
 * 为了使得递推公式更加一般性，可以进行一个改变：
 * 在上述的计算过程中，如果在第 j 天买入的话，获得的利润值中加上了 dp[j-1][t-1] 项，其实把这一项变成 dp[j][t-1]对结果是没有影响的
 * 试想如果第 j 天是最后选择的买入点，它使得最后的收益最高，那么 dp[j-1][t-1] 和 dp[j][t-1] 是相等的
 * 因为第 j 天一定是一个低点，而 第j-1 天一定是一个高点（如果反过来的话，就不会在第j-1天卖掉，然后在第j天再买了，就会直接选择到第 j 天卖掉即可）
 * 所以为了得到更高的利润，第 j 天选择不操作，和 j-1 天的利润是一样的
 * 递推公式：dp[i][t] = max(dp[i-1][t], max(price[i]-price[0]+dp[0][t-1],  price[i]-price[1]+dp[1][t-1],  ...  ,  price[i]-price[j]+dp[j][t-1]))
 * 
 * 方法：
 * 从底向上进行计算
 * 对于t=1的情况，计算在这一天之前的每一天买入且在当前天卖出的最大利润，然后与当前天不操作时的最大利润进行比较，挑选较大的一个，就是当前天的最大利润
 * 以此类推t=2的情况
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int k = 2; // 限制交易次数为2次
    vector<vector<int>> dp(prices.size(), vector<int>(k+1, 0));
    for (int t = 1; t <= k; t++) {
        // 如果第 0 天买入，那么获得的利润是 price[i] - price[0]，min_value相当于price[0]
        int min_value = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            // 由于要计算 price[i]-price[j]+dp[j][t-1]，可以将其看成 price[i]-(price[j]-dp[j][t-1])，每次更新 price[j]-dp[j][t-1] 的最小值，然后可以直接计算 price[i]-(price[j]-dp[j][t-1])
            // 找出第 1 天到第 i 天 prices[i] - dp[i][t-1] 的最小值
            min_value = min(prices[i] - dp[i][t - 1], min_value);
            // 比较不操作和选择一天买入的哪个值更大
            dp[i][t] = max(dp[i - 1][t], prices[i] - min_value);
        }
    }
    return dp[prices.size() - 1][k];
}

/* 
 * 上述方法中，动态规划的填表法是固定t，然后对dp进行逐列更新，为了后续的优化可以将两层循环进行颠倒
 * 由于上述的方法中，固定了t每一次更新dp的一列，即在公式 price[i]-(price[j]-dp[j][t-1])，t不会变，所以用一个变量就可以对 price[j]-dp[j][t-1] 的最小值进行更新
 * 但是当颠倒了两层循环之后是固定行然后对 t 每次更新一行，所以一个变量已经无法求得 price[j]-dp[j][t-1] 的最小值，所以需要一个数组来存储不同的 t 对应的最小值
 */
int maxProfit_optimize(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int k = 2;
    vector<vector<int>> dp(prices.size(), vector<int>(k+1, 0));

    vector<int> min_value(k+1, 0);
    for (int i = 1; i <= k; i++) {
        min_value[i] = prices[0];
    }

    for (int i = 1; i < prices.size(); i++) {
        for (int t = 1; t <= k; t++) {
            min_value[t] = min(prices[i] - dp[i][t - 1], min_value[t]);
            // 比较不操作和选择一天买入的哪个值更大
            dp[i][t] = max(dp[i - 1][t], prices[i] - min_value[t]);
        }
    }
    return dp[prices.size() - 1][k];
}

/* 
 * 上述方法中，动态规划的填表法改成了固定行然后对t每次更新一行，然后用一个数组min_value来保存不同 t 时 price[i]-dp[i][t-1] 的最小值
 * 可以发现因为每次更新一行，所以dp数组中对当前行更新有用的值仅仅是前一行，所以可以将dp二维数组修改为一维数组
 */
int maxProfit_optimize2(vector<int>& prices) {
    if (prices.empty()) {
        return 0;
    }
    int k = 2;
    vector<int> dp(k+1, 0);
    vector<int> min_value(k+1, 0);

    for (int i = 1; i <= k; i++) {
        min_value[i] = prices[0];
    }

    for (int i = 1; i < prices.size(); i++) {
        for (int t = 1; t <= k; t++) {
            min_value[t] = min(prices[i] - dp[t - 1], min_value[t]);
            // 比较不操作和选择一天买入的哪个值更大
            dp[t] = max(dp[t], prices[i] - min_value[t]);
        }
    }
    return dp[k];
}

/* 
 * 上述方法中，动态规划的填表法改成了固定行然后对t每次更新一行，然后用一个数组min_value来保存不同 t 时 price[i]-dp[i][t-1] 的最小值
 * 可以发现因为每次更新一行，所以dp数组中对当前行更新有用的值仅仅是前一行，所以可以将dp二维数组修改为一维数组
 */
int maxProfit_optimize3(vector<int>& prices) {
     if (prices.empty()) {
        return 0;
    }
    int k = 2;
    int dp1 = 0, dp2 = 0;
    int min1 = prices[0], min2 = prices[0];

    for (int i = 1; i < prices.size(); i++) {
        // 下列两行相当于上一个方法中的 
        // min_value[t] = min(prices[i] - dp[t - 1], min_value[t]);
        // 当t变量等于1时，dp[t-1]等于0，所以下面式子中 -0 是为了更好得对比理解
        min1 = min(prices[i] - 0, min1);
        // dp[t] = max(dp[t], prices[i] - min_value[t]);
        dp1 = max(dp1, prices[i] - min1);

        // 下列两行相当于上一个方法中的 
        // min_value[t] = min(prices[i] - dp[t - 1], min_value[t]);
        // 当t变量等于2时，dp[t-1]就是第一个参数dp1
        min2 = min(prices[i] - dp1, min2);
        // dp[t] = max(dp[t], prices[i] - min_value[t]);
        dp2 = max(dp2, prices[i] - min2);
    }
    return dp2;
}

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    auto ret = maxProfit(prices); // 6
    cout << ret;
    return 0;
}
