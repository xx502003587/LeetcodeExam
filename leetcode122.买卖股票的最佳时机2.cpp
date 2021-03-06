/*
 * 题意：
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 你可以尽可能地完成更多的交易（多次买卖一支股票）。设计一个算法来计算你所能获取的最大利润。
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 * 如 [7,1,5,3,6,4] 
 * 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4
 * 随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3
 *
 * 思路：
 * 由于不限制交易次数，只要明天的价格比今天高，那么今天买了明天卖就能够获得利润
 * 所以只需要对连续上升的序列直接计算差值即可
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int max = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i-1]) {
            max += prices[i] - prices[i-1];
        }
    }
    return max;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4}; 
    auto ret = maxProfit(prices); // 7
    cout << ret;
    return 0;
}
