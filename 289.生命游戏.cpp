/*
 * 遍历格子的每个位置，对该位置的8个邻居的活细胞个数进行计数
 * 因为所有格子的值需要被同步更新，所以需要将每个位置的值更新为他即将变化的方向，当所有格子更新完毕之后，再对格子进行遍历，将变化方向修改为状态
 * 活细胞是1，如果该细胞即将死亡，则将其更新为2（只要是一个大于1的数就行，因为当前位置更新后，该位置还会作为其他格子的邻居来进行计数，该数保持为正可以直接判断是否>1来判断活细胞）
 * 死细胞是0，如果该细胞即将复活，则将其更新为-1（只要是一个负数就行，因为当前位置更新后，该位置还会作为其他格子的邻居来进行计数，该数保持非正可以直接判断是否<=0来判断死细胞）
 * 
 * 如果当前细胞为活细胞，即格子为1
 * 1. 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡，更新为2
 * 2. 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡，更新为2
 * 如果当前细胞为死细胞，即格子为0
 * 1. 如果死细胞周围正好有三个活细胞，则该位置死细胞复活，更新为-1
 * 
 * 遍历格子的每个位置，对方向进行更新，将2更新为0，将-1更新为1即可
 */

#include <iostream>
#include <vector>

using namespace std;

void changeBoard(vector<vector<int>>& board, int row, int col) {
    int live = 0;
    int m = board.size();
    int n = board[0].size();

    for (int i = row - 1; i <= row + 1; ++i) {
        for (int j = col - 1; j <= col + 1; ++j) {
            if (i == row && j == col) {
                continue;
            }
            if (i >= 0 && i < m && j >= 0 && j < n) {
                if (board[i][j] > 0) {
                    ++live;
                }
            }
        }
    }
    // 当前为活细胞
    if (board[row][col] == 1) {
        // 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡
        if (live < 2)
            board[row][col] = 2;
        // 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡
        if (live > 3)
            board[row][col] = 2;
    }
        // 当前为死细胞
    else {
        // 如果死细胞周围正好有三个活细胞，则该位置死细胞复活
        if (live == 3)
            board[row][col] = -1;
    }
}

void gameOfLife(vector<vector<int>>& board) {
    int m = board.size();
    if (m == 0)
        return;
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            changeBoard(board, i, j);
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 2)
                board[i][j] = 0;
            if (board[i][j] == -1)
                board[i][j] = 1;
        }
    }
}

int main() {
    vector<vector<int>> board = {{0,1,0},
                                 {0,0,1},
                                 {1,1,1},
                                 {0,0,0}};
    gameOfLife(board);
    for (auto i : board) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
