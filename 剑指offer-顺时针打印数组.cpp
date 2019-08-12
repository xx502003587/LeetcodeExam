/*
 * 题意：
 * 该题不涉及任何复杂的算法和数据结构，难点在于判断多个边界条件
 * 以下面4x4表格为例
 * 1  2  3  4
 * 5  6  7  8
 * 9  10 11 12
 * 13 14 15 16
 * 正确的打印顺序应该为：1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
 * 
 * 思路：
 * 假设行数是rows，列数是cols，打印第一圈时左上角为(0,0)，第二圈时左上角为(1,1)，以此类推
 * 可以发现，当矩阵是5x5时，最后一圈只有一个数字，对应坐标为(2,2)，5>2*2
 * 当矩阵是6x6时，最后一圈左上角对应的坐标为(2,2)，6>2*2
 * 所以可以发现 cols > start * 2 && rows > start * 2 作为判断循环是否终止的条件来进行每一圈数的打印
 * 在循环内部，每一圈需要打印的数存在四种情况：
 * 1. 必然存在————从左往右输出一行
 * 2. 可能存在————从上往下输出一列（说明表格至少有两行即：终止行号 > 起始行号）
 * 3. 可能存在————从右往左输出一行（说明表格至少为两行两列即：终止行号 > 起始行号 && 终止列号 > 起始列号）
 * 4. 可能存在————从下往上输出一列（说明表格至少为三行两列即：终止行号 > 起始行号 + 1）
 * 顺序进行四种情况的判断即可
 */

#include <iostream>
#include <vector>

using namespace std;

void PrintMatrixInCircle(vector<vector<int>> &numbers, int rows, int cols, int start) {
    int endx = cols - start - 1;
    int endy = rows - start - 1;
    // 1. 从左到右打印一行
    for (int i = start; i <= endx; ++i) {
        cout << numbers[start][i] << " ";
    }
    // 2. 如果存在，从上往下打印一行
    if (start < endy) {
        for (int i = start + 1; i <= endy; ++i) {
            cout << numbers[i][endx] << " ";
        }
    }
    // 3. 如果存在，从右往左打印一行
    if (start < endy && start < endx) {
        for (int i = endx - 1; i >= start; --i) {
            cout << numbers[endy][i] << " ";
        }
    }
    // 4. 如果存在，从下往上打印一行
    if (start + 2 <= endy && start < endx) {
        for (int i = endy - 1; i > start; --i) {
            cout << numbers[i][start] << " ";
        }
    }
}

void PrintMatrixClockwisely(vector<vector<int>> &numbers, int rows, int cols) {
    if (numbers.empty()) {
        return;
    }
    int start = 0;
    // 每次循环挑选的是一圈的左上角坐标
    while (rows > start * 2 && cols > start * 2) {
        PrintMatrixInCircle(numbers, rows, cols, start);
        ++start;
    }
    cout << endl;
}

int main() {
    // 对应四种情况的测试用例
    vector<vector<int>> numbers_4x4 = {{1,  2,  3,  4},
                                       {5,  6,  7,  8},
                                       {9,  10, 11, 12},
                                       {13, 14, 15, 16}};
    vector<vector<int>> numbers_1x4 = {{1, 2, 3, 4}};
    vector<vector<int>> numbers_4x1 = {{1},
                                       {2},
                                       {3},
                                       {4}};
    vector<vector<int>> numbers_1x1 = {{1}};

    cout << "numbers_4x4 result is" << endl;
    PrintMatrixClockwisely(numbers_4x4, numbers_4x4.size(), numbers_4x4[0].size());
    cout << "numbers_1x4 result is" << endl;
    PrintMatrixClockwisely(numbers_1x4, numbers_1x4.size(), numbers_1x4[0].size());
    cout << "numbers_4x1 result is" << endl;
    PrintMatrixClockwisely(numbers_4x1, numbers_4x1.size(), numbers_4x1[0].size());
    cout << "numbers_1x1 result is" << endl;
    PrintMatrixClockwisely(numbers_1x1, numbers_1x1.size(), numbers_1x1[0].size());
    return 0;
}
