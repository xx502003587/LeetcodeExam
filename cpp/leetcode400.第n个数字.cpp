/*
 * 题意：
 * 在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。
 * 注意:
 * n 是正数且在32为整形范围内 ( n < 231)。
 *
 * 思路：
 * 1位数：共有 1*1*9 个数字
 * 2位数：共有 2*10*9 个数字
 * 3位数：共有 3*100*9 个数字
 * k位数：共有 k*10^(k-1)*9个数字
 * 其中k表示每一个数都有k个数字
 * 10^(k-1)表示从k位数的第一个数开始，最高位从i变到i+1会经过10^(k-1)个数，例如2位数，从10到20中间有10^1个数（10~19）；3位数，从100到200中间有10^2个数（100~199）
 * 9表示上述从i变到i+1总共能变9次，即1xx、2xx、……、9xx
 *
 * 首先根据上述思路确定第n个数字落在几位数区间内
 * 然后判断第n个数字所在的那个数是该区间内的第几个数
 * 接着判断第n个数字处于它所在的那个数的第几个位置
 * 最后根据上述计算出所在的那个数，然后返回对应位置的那个数字
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findNthDigit(int n) {
    int k = 0; // k表示数的位数
    long count = 0;
    while (count < n) {
        k++;
        count += k * (pow(10, k - 1)) * 9;
    }
    // 当count大于等于n时，先退回到上一个值，clip_num表示在k位数的区间内位于第几个位置（从1开始计数）
    int clip_num = n - count + k * pow(10, k - 1) * 9;
    // k_num 表示第n个数字在k位数的区间内位于第几个数，由于该区间内每个数都是k位，所以直接对k取整即可（-1操作是因为上述位置是从1开始计数的）
    int k_num = (clip_num - 1) / k;
    // k_end 表示第n个数字在它所处的那个数中是第几个位置
    int k_end = (clip_num - 1) % k;
    // 找到第n个数字所在的那个数
    int num = pow(10, k - 1) + k_num;
    // 返回该数对应的字符串的k_end索引的数字即可
    return to_string(num)[k_end] - '0';
}

int main() {
    int n = 1000000000;
    auto ret = findNthDigit(n);
    cout << ret; // 1
    return 0;
}
