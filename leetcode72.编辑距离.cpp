/*
 * 题意：
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 你可以对一个单词进行如下三种操作：
 * 插入一个字符、删除一个字符、替换一个字符
 *
 * 思路：
 * 动态规划
 * 令 dp[i][j] 表示将 word1 的前 i 个字母和 word2 的前 j 个字母之间的编辑距离
 * 1. 如果两个单词的最后一个字母相同，即 word1[i] == word2[j] 时，那么dp[i][j] = dp[i-1][j-1]，即对这一位字母不需要进行操作
 * 2. 如果两个单词的最后一个字母不同，有3种情况：
 *    在 word1[i] 后面插入 word2[j]，那么 dp[i][j] = dp[i][j-1] + 1
 *    将 word1[i] 字符删除，那么 dp[i][j] = dp[i-1][j] + 1
 *    将 word1[i] 字符替换成 word2[j]，那么 dp[i][j] = dp[i-1][j-1] + 1
 * 所以 dp[i][j] 应该是上述中最小的一个
 */

#include <iostream>
#include <vector>

using namespace std;

int minDistance(string word1, string word2) {
    int n = word1.length();
    int m = word2.length();
    if (m * n == 0) {
        return m + n;
    }

    vector<vector<int>> ret(n+1, vector<int>(m+1,0));

    for (int i = 0; i < n+1; i++) {
        ret[i][0] = i;
    }
    for (int j = 0; j < m+1; j++) {
        ret[0][j] = j;
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            int tl = ret[i-1][j-1];
            if (word1[i-1] != word2[j-1]) {
                tl += 1;
            }
            ret[i][j] = min(min(ret[i-1][j] + 1, ret[i][j-1] + 1), tl);
        }
    }
    return ret[n][m];
}

int main() {
    string word1 = "horse";
    string word2 = "ros";
    auto ret = minDistance(word1, word2);
    cout << ret << endl;

    return 0;
}
