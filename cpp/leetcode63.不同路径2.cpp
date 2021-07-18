/*
 * 题意：
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 *
 * 思路：
 * 与leetcode62题思路类似，但是由于有障碍物的存在，需要进行一些小调整
 * 对于一个位置来说，可以从上边到达，也可以从左边到达，所以在62题中将两个数值相加就是当前位置的路径数
 * 由于障碍物的存在，可能导致当前位置无法从上边到达（上边是石头），或者无法从左边到达（左边是石头）
 * 此时的计算过程如下
 * 1. 如果当前位置是石头，就把可以到达当前位置的不同路径数设置为0，这样如果计算该位置下边或者右边的时候，从石头处到达下边或右边的路径就是0（因为无法从石头到达下边或者右边）
 * 2. 如果当前位置不是石头，就累加上面位置和左边位置到达的不同路径数，作为到达当前位置的路径数。（如果上边是石头，那么路径数就等于左边；如果左边是石头，那么路径数就等于上边）
 * 
 * 由于出现了障碍物，所以对dp矩阵进行初始化时也要注意，对于第一行或者第一列的数值，在62题中是直接设置为1，因为向下和向右都可以到达
 * 如果第一行（第一列）中出现了障碍物，就表明往右走（往下走）最多只能走到障碍物的前一个（上一个），所以能到达的位置设置为1，不能到达的位置设置为0
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<long>> dp(m, vector<long>(n, 0));
    // 如果起点就是石头，那么直接返回0
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }
    dp[0][0] = 1;
    // 如果第一列中某个位置有石头，那么石头上面的都初始化为1，石头下面都为0
    for (auto i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] == 0) {
            dp[i][0] = dp[i - 1][0];
        } else {
            dp[i][0] = 0;
            break;
        }
    }
    // 如果第一行中某个位置有石头，那么石头左边的都初始化为1，石头右边都为0
    for (auto j = 1; j < n; ++j) {
        if (obstacleGrid[0][j] == 0) {
            dp[0][j] = dp[0][j - 1];
        } else {
            dp[0][j] = 0;
            break;
        }
    }

    for (auto i = 1; i < m; ++i) {
        for (auto j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    vector<vector<int>> obstacleGrid = {{0, 0, 0},
                                        {0, 1, 0},
                                        {0, 0, 0}};
    auto ret = uniquePathsWithObstacles(obstacleGrid);
    cout << ret << " "; // 2
    return 0;
}
