/*
 * 题目：
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 *
 * 思路：
 * 考虑一个2x8的矩阵区域，记其结果为f(8)。当用一个2x1的小矩形去覆盖大矩形最左边时有两个选择：
 * 1. 当这个小矩形竖起来放的时候，右边还剩下2x7的区域，即f(7)
 * 2. 当这个小矩形横起来放在左上角的时候，左下角必须也横着放一个小矩形，右边还剩下2x6的区域，即f(6)
 * 所以该题也是斐波那契的一个应用
 */

#include <iostream>

using namespace std;

int rectCover(int number) {
    if (number == 1) {
        return number;
    }
    int f0 = 1;
    int f1 = 1;
    int f2 = 0;
    for (int i = 2; i <= number; i++) {
        f2 = f0+f1;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}

int main() {
    auto ret = rectCover(3);
    cout << ret << endl;
    return 0;
}
