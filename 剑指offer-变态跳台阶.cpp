/*
 * 题目：
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 *
 * 思路：
 * 由跳台阶规律可推得，若一次能跳1阶或者2阶，那么f(n) = f(n-1) + f(n-2)
 * 所以该题的规律为 f(n) = f(n-1) + f(n-2) + …… + f(1)
 * 因为该项等号后面的项数无法确定，所以可以使用一个for循环来解决
 * 还可以通过数学公式来简单推理：
 * f(n) = f(n-1) + f(n-2) + …… + f(1)
 * f(n-1) = f(n-2) + f(n-3) + …… + f(1)
 * 两式相减，得到 f(n) = 2f(n-1)
 * 因为f(1) = 1，所以直接迭代计算即可。
 * 所以该题也是斐波那契的一个应用
 */

#include <iostream>

using namespace std;

int jumpFloorII(int number) {
    if (number == 0) {
        return number;
    }
    int count = 1;
    for (int i = 2; i <= number; i++) {
        count *= 2;
    }
    return count;
}

int main() {
    auto ret = jumpFloorII(5);
    cout << ret << endl;
    return 0;
}
