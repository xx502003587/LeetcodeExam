/*
 * 题意：
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 问总共有多少条不同的路径？
 *
 * 思路：
 * 动态规划思路
 * 令 dp[i][j] 表示走到 (i,j) 位置时一共有多少种不同的路径
 * 递推公式为 dp[i][j] = dp[i-1][j] + dp[i][j-1]
 * 理解：每个位置都可以从当前位置的上面到达或者从左边到达，将两个位置的路径数量加起来就是到达当前位置的路径数量
 * 由于只能向右或者向下走，所以对于 (i,0) 或 (0,j) 的位置，都只有一种走法
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
        dp[i][0] = 1;

    for (int i = 0; i < n; ++i)
        dp[0][i] = 1;

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

/*
 * 由于每一次计算当前位置的只需要上边和左边的数，所以可以将空间复杂度优化到O(N)
 * 将dp数组设置为全1，然后从(1,1)位置开始遍历，共遍历m次，相当于每次更新一行
 * 对于每一行中的更新，每个位置等于当前位置的数加上前一个位置的数
 * 对第一行的更新过程如下：dp[0]的位置永远是1，第二个位置用 dp[0]+dp[1]=1+1=2 对应上述方法中 dp[1][0]+dp[0][1]，此时第二个位置的数更新为2
 * 第三个位置用dp[2]+dp[1]=1+2=3 对应上述方法中 dp[1][1]+dp[0][2]
 * 以此类推，相当于每一行更新后将对应的数进行覆盖，下一行直接使用当前数和前一个数进行更新即可
 */
int uniquePaths_optimize(int m, int n) {
    vector<int> dp(n, 1);

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[j] += dp[j-1];
        }
    }
    return dp.back();
}

int main() {
    int m = 3, n = 2;
    auto ret = uniquePaths(m, n);
    cout << ret << " "; // 3
    return 0;
}
