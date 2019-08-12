/**
 * 题意：
 * 与顺时针打印数组类似，输入是一个正整数n，输出为n阶方阵，输出结果应保证从1开始顺时针递增，如下为n=3的结果
 * n=3时：
 * 7  8  9	
 * 6  1  2	
 * 5  4  3
 * n=4时：
 * 7  8  9  10
 * 6  1  2  11
 * 5  4  3  12
 * 16 15 14 13
 * 
 * 思路：
 * 由输出结果可以发现规律，对n进行奇数和偶数区分
 * 当n为奇数时，输出方阵的右上角为n的平方，逆时针递减一圈，然后向内缩小一圈后，n减小2，重复上述操作
 * 当n为偶数时，输出方阵的左下角为n的平方，逆时针递减一圈，然后向内缩小一圈后，n减小2，重复上述操作
 * 
 * 所以可以根据每一圈输入的坐标和圈的size来确定对角坐标，然后根据坐标用4个for循环分别打印4条边即可
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * numbers: 数组
 * r: 该圈输入的行坐标
 * c: 该圈输入的列坐标
 * start: 该圈的size大小
 * cur: 该圈的第一个数
 */ 
void PrintMatrixInCircle_Odd(vector<vector<int>> &numbers, int r, int c, int start, int cur) {
    // 奇数情况
    // 从右上角逆时针打印一圈，所以(r,c)为右上角坐标，该圈左下角坐标为(r+start-1, c-start+1)
    int lbr = r+start-1;
    int lbc = c-start+1;

    // 从(r,c)开始，自右向左打印一行，一直打印到(r, lbc)
    for (int i = c; i >= lbc; --i) {
        numbers[r][i] = cur--;
    }
    // 从(r,lbc)的下一个位置开始，从上向下打印一列，一直打印到(lbr,lbc)
    for (int i = r + 1; i <= lbr; ++i) {
        numbers[i][lbc] = cur--;
    }
    // 从(lbr,lbc)的右一个位置开始，自左向右打印一行，一直打印到(lbr,c)
    for (int i = lbc + 1; i <= c; ++i) {
        numbers[lbr][i] = cur--;
    }
    // 从(lbr,c)的上一个位置开始，自下向上打印一列，一直打印到(r+1,c)
    for (int i = lbr - 1; i > r; --i) {
        numbers[i][c] = cur--;
    }
}

void PrintMatrixInCircle_Even(vector<vector<int>> &numbers, int r, int c, int start, int cur) {
    // 偶数情况 
    // 从左下角逆时针打印一圈，所以(r,c)为左下角坐标，该圈右上角坐标为(r-start+1, c+start-1)
    int trr = r-start+1;
    int trc = c+start-1;

    // 从(r,c)开始，自左向右打印一行，一直打印到(r, trc)
    for (int i = c; i <= trc; ++i) {
        numbers[r][i] = cur--;
    }
    // 从(r, trc)的上一个位置开始，从下向上打印一列，一直打印到(trr,trc)
    for (int i = r - 1; i >= trr; --i) {
        numbers[i][trc] = cur--;
    }
    // 从(trr,trc)的左一个位置开始，自右向左打印一行，一直打印到(trr,c)
    for (int i = trc - 1; i >= c; --i) {
        numbers[trr][i] = cur--;
    }
    // 从(trr,c)的下一个位置开始，自上向下打印一列，一直打印到(r-1,c)
    for (int i = trr + 1; i < r; ++i) {
        numbers[i][c] = cur--;
    }
}

void PrintMatrixClockwisely(vector<vector<int>> &numbers, int size) {
    int start = size;
    // 如果是偶数阶方阵，从左下角开始逆时针打印
    if (size % 2 == 0) {
        int r = start - 1;
        int c = 0;
        while (start > 0) {
            PrintMatrixInCircle_Even(numbers, r, c, start, pow(start,2));
            start -= 2;
            r -= 1;
            c += 1;
        }
    }
    // 如果是奇数阶方阵，从右上角开始逆时针打印
    else {
        int r = 0;
        int c = start - 1;
        while (start >= 1) {
            PrintMatrixInCircle_Odd(numbers, r, c, start, pow(start,2));
            start -= 2;
            r += 1;
            c -= 1;
        }
    }
}

int main() {
    int input = 1;
    vector<vector<int>> numbers(input, vector<int>(input, 0));
    if (input == 0) {
        return 0;
    }
    PrintMatrixClockwisely(numbers, input);

    // 格式化输出方阵
    for (auto out : numbers) {
        for (auto in : out) {
            cout << in << "\t";
        }
        cout << endl;
    }
    return 0;
}
