/*
 * 题意：
 * 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * n = 3
 * [ 1, 2, 3 ],
 * [ 8, 9, 4 ],
 * [ 7, 6, 5 ]
 *
 * 思路：
 * 题解见 剑指offer-顺时针打印数组.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintMatrixClockwisely(int rows, int cols, int start, int& count, vector<vector<int>>& ret) {
    int endx = cols - start - 1;
    int endy = rows - start - 1;
    // 1. 从左到右打印一行
    for (int i = start; i <= endx; ++i) {
        ret[start][i] = count++;
    }
    // 2. 如果存在，从上往下打印一行
    if (start < endy) {
        for (int i = start + 1; i <= endy; ++i) {
            ret[i][endx] = count++;
        }
    }
    // 3. 如果存在，从右往左打印一行
    if (start < endy && start < endx) {
        for (int i = endx - 1; i >= start; --i) {
            ret[endy][i] = count++;
        }
    }
    // 4. 如果存在，从下往上打印一行
    if (start + 2 <= endy && start < endx) {
        for (int i = endy - 1; i > start; --i) {
            ret[i][start] = count++;
        }
    }
}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, vector<int>(n, 0));
    int start = 0;
    int count = 1;
    // 每次循环挑选的是一圈的左上角坐标
    while (n > start * 2) {
        PrintMatrixClockwisely(n, n, start, count, ret);
        ++start;
    }
    return ret;
}

int main() {
    int n = 5;
    auto numbers = generateMatrix(n);

    // 格式化输出方阵
    for (auto out : numbers) {
        for (auto in : out) {
            cout << in << "\t";
        }
        cout << endl;
    }
    return 0;
}