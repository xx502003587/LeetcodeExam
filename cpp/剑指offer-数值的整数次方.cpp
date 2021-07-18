/*
 * 题目：
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 *
 * 思路：
 * 因为exponent可能为0或者负数，所以无法直接简单地对将base连乘exponent次
 * 如果exp为负数，则计算方式为先计算base的abs(exp)次方，然后取倒数即可。
 * 如果exp为0时，base也为0，在数学上没有意义，输出0（需向面试官说明清楚）
 * 如果base为0时，exp为负数，在数学上没有意义，输出0
 */

#include <iostream>

using namespace std;

/* 此处为求次方的优化方法
 * 如果直接使用连乘方法，对于32次方需要做31次乘法，但是我们知道32次方是16次方的2次方，16次方是8次方的2次方，8次方是4次方的2次方，4次方是2次方的2次方
 * 所以如果直接对该数平方，在平方的基础上求4次方，再求8次方，16次方，32次方，只需要5次乘法即可。
 * 即：n为偶数时，a的n次方 = a的n/2次方 * a的n/2次方
 *     n为奇数时，a的n次方 = a的(n-1)/2次方 * a的(n-1)/2次方 * a
 */
double PowerWithUnsignedExponent(double base, unsigned int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if (exponent & 0x1 == 1) {
        result *= base;
    }
    return result;
}

// 对double和float判断等于时会有误差，不能直接用==判断，要判断两数之差的绝对值是否小于一个特别小的数
bool equal0(double num) {
    if (num > -0.0000001 && num < 0.0000001) {
        return true;
    }
    return false;
}

double Power(double base, int exponent) {
    // 非法情况
    if (equal0(base) && exponent < 0) {
        return 0;
    }
    // 获取exp的绝对值n
    auto absExponent = (unsigned int)exponent;
    if (exponent < 0) {
        absExponent = (unsigned int)(-exponent);
    }
    // 先计算base的abs(exp)次方
    double result = PowerWithUnsignedExponent(base, absExponent);
    // 如果次方小于0，取倒数
    if (exponent < 0) {
        result = 1.0 / result;
    }
    return result;
}

int main() {
    auto ret = Power(2,4);
    cout << "pow(2,4)=" << ret << endl;

    ret = Power(2,-4);
    cout << "pow(2,-4)=" << ret << endl;

    ret = Power(0,4);
    cout << "pow(0,4)=" << ret << endl;

    ret = Power(0,-1);
    cout << "pow(0,-1)=" << ret << endl;

    return 0;
}
