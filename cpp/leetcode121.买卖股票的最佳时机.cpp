/*
 * 题意：
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 * 注意你不能在买入股票前卖出股票。
 * 如 [7,1,5,3,6,4] 
 * 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 *
 * 思路：
 * 由于限制只能交易一次，所以如果将股票价格看做折线图的话，要求的值就是最小的波谷之后的最大的波峰
 * 维护一个全局最小值表示 min_price，维护一个全局最大值表示当前价格减去 min_price 后得到的最大利润值
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    // 更新全局最小价格
    int minPrice = INT_MAX;
    int maxPro = 0;
    for (int i = 0; i < prices.size(); ++i) {
        // 如果当前价格比最小价格小，更新最小价格
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } 
        // 如果当前价格比最小价格高，判断如果今天卖出得到的利润是否大于全局最大利润
        else if (prices[i] - minPrice > maxPro) {
            maxPro = prices[i] - minPrice;
        }
    }
    return maxPro;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4}; 
    auto ret = maxProfit(prices); // 5  
    cout << ret;
    return 0;
}
