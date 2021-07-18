/*
 * 题目：
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
 * 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 *
 * 思路：
 * 
 */

#include <iostream>

using namespace std;

int jumpFloor(int number) {
    int f1 = 1;
    if (number <= 2) {
        return number;
    }
    int f2 = 2;
    int f3 = 0;
    for (int i = 3; i <= number; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

int main() {
    auto ret = jumpFloor(5);
    cout << ret << endl;

    return 0;
}
