/*
 * 题目：
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
 *
 * 思路：
 * 递归方法会非常耗时，所以使用动态规划方法来解决。
 * 每一个数等于前两个数的和。
 */

#include <iostream>

using namespace std;

int Fibonacci(int n) {
    int f0 = 0;
    int f1 = 1;
    if (n <= 1) {
        return n;
    }
    int f2 = 0;
    for (int i = 2; i <= n; i++) {
        f2 = f1 + f0;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}

int main() {
    auto ret = Fibonacci(10);
    cout << ret << endl;
    return 0;
}
