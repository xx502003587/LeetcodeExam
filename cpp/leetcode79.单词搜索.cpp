/*
 * 题意：
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
 * 同一个单元格内的字母不允许被重复使用。
 *
 * 思路：
 * 在每个位置向四个方向进行DFS搜索+回溯
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 判断坐标 (x,y) 是否有效
bool check_x_y(vector<vector<char>> &board, int x, int y) {
    if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size()) {
        return true;
    }
    return false;
}

bool dfs(vector<vector<char>> &board, string &word, vector<vector<bool>> &mark,
         vector<pair<int, int>> &direction, int i, int j, int start) {
    // 如果当前字符是 word 的最后一个字符，直接判断是否相等即可
    if (start == word.length() - 1) {
        return board[i][j] == word[start];
    }
    // 如果不是最后一个字符，在判断过后还需要进行DFS递归
    if (board[i][j] == word[start]) {
        // 先将格子标记为 “已访问”
        mark[i][j] = true;
        // 向四个方向递归
        for (int k = 0; k < 4; ++k) {
            int x = i + direction[k].first;
            int y = j + direction[k].second;
            // 如果坐标 (x,y) 合法并且还没被访问过，进行递归
            if (check_x_y(board, x, y) && !mark[x][y]) {
                if (dfs(board, word, mark, direction, x, y, start + 1)) {
                    return true;
                }
            }
        }
        // 回溯回来之后，要将当前格子设置为“未访问”
        mark[i][j] = false;
    }
    return false;
}

bool exist(vector<vector<char>> &board, string word) {
    int m = board.size();
    if (m == 0) {
        return false;
    }
    int n = board[0].size();
    vector<vector<bool>> mark(m, vector<bool>(n, false));

    vector<pair<int, int>> direction = {{0,  1},
                                        {0,  -1},
                                        {1,  0},
                                        {-1, 0}};

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dfs(board, word, mark, direction, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','C','S'},
                                  {'A','D','E','E'}};
    string word = "ABCCED";
    cout << exist(board, word); // 1
    return 0;
}
