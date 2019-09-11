/*
 * 题意：
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 *
 * 思路：
 * 题解见 剑指offer-顺时针打印数组.cpp
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintMatrixInCircle(vector<vector<int>> &numbers, int rows, int cols,
                         int start, vector<int> &ret) {
    int endx = cols - start - 1;
    int endy = rows - start - 1;
    // 1. 从左到右打印一行
    for (int i = start; i <= endx; ++i) {
        ret.push_back(numbers[start][i]);
    }
    // 2. 如果存在，从上往下打印一行
    if (start < endy) {
        for (int i = start + 1; i <= endy; ++i) {
            ret.push_back(numbers[i][endx]);
        }
    }
    // 3. 如果存在，从右往左打印一行
    if (start < endy && start < endx) {
        for (int i = endx - 1; i >= start; --i) {
            ret.push_back(numbers[endy][i]);
        }
    }
    // 4. 如果存在，从下往上打印一行
    if (start + 2 <= endy && start < endx) {
        for (int i = endy - 1; i > start; --i) {
            ret.push_back(numbers[i][start]);
        }
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ret;
    if (matrix.empty()) {
        return ret;
    }
    int start = 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    // 每次循环挑选的是一圈的左上角坐标
    while (rows > start * 2 && cols > start * 2) {
        PrintMatrixInCircle(matrix, rows, cols, start, ret);
        ++start;
    }
    return ret;
}

int main() {
    vector<vector<int>> matrix = {{1, 2,  3,  4},
                                  {5, 6,  7,  8},
                                  {9, 10, 11, 12}};
    auto ret = spiralOrder(matrix); // [1,2,3,4,8,12,11,10,9,5,6,7]
    for (auto num : ret) {
        cout << num << " ";
    }

    return 0;
}