/*
 * 题意：
 * 给定一个正数数组序列，选出一个区间，使得该区间是所有区间中经过如下计算后值最大的一个：
 * 区间中的最小值 * 区间和
 *
 * 思路：
 * 1. 暴力解法————时间复杂度O(n^2)
 * 双重循环遍历数组的每个可能区间，每个区间的结果与全局最优解进行比较与更新
 * 
 * 2. 优化的暴力解法————时间复杂度O(n^2)
 * 由于数组中都是正数，所以如果固定一个数为最小值，那么在以该值为最小值的区间中，肯定是数越多乘积越大
 * 遍历数组的每一个数，寻找以该数为最小值的连续区间，将结果与全局最优进行比较与更新
 * 
 * 3. 利用单调栈进行解题————时间复杂度O(n)
 * https://blog.csdn.net/u013616945/article/details/77508372
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int max_result(const vector<int>& score) {
    int sum = 0;
    int max_res = INT_MIN;
    int tmp_max = 0;
    for (int i = 0; i < score.size(); ++i) {
        sum = score[i];
        for (int j = i - 1; j >= 0; --j) {
            if (score[j] >= score[i]) {
                sum += score[j];
            } else {
                break;
            }
        }
        for (int k = i + 1; k < score.size(); ++k) {
            if (score[k] >= score[i]) {
                sum += score[k];
            } else {
                break;
            }
        }
        tmp_max = sum * score[i];
        max_res = tmp_max > max_res ? tmp_max : max_res;
    }
    return max_res;
}

int main() {
    vector<int> score = {7,2,4,6,5};
    auto max_res = max_result(score);
    cout << max_res;
    return 0;
}