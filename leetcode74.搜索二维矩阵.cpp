/*
 * 题意：
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 *
 * 思路：
 * 根据矩阵的特性，每一行从左到右升序，每一个行的第一个整数大于前一行的最后一个整数
 * 所以如果将整个二维数组按行展开成一维数组后，应该是升序的序列
 * 所以查找数的时候就可以使用二分法来进行寻找，每次更改left mid right时 只需要根据一维数组到二维数组的映射关系进行修改即可
 * 一维数组的[i] 对应 二维数组的[i / n][i % n]
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    if (m == 0) {
        return false;
    }
    int n = matrix[0].size();
    int left = 0, right = m * n - 1;
    int mid = 0;
    int mid_value = 0;

    while (left <= right) {
        mid = left + ((right - left) >> 1);
        mid_value = matrix[mid / n][mid % n];
        if (mid_value == target) {
            return true;
        } else if (mid_value > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1,  3,  5,  7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 50}};
    int target = 3;
    auto ret = searchMatrix(matrix, target);
    cout << ret << " ";
    return 0;
}
