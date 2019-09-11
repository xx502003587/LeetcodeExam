/*
 * 题意：
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 *
 * 思路：
 * 动态规划法，类似于斐波那契数列
 * 令dp[i]表示到第i个字符位置，能够产生的组合个数
 * 递推公式：后一个字符与前缀若干个字符组合可以通过公式 dp[i] = dp[i-1] + dp[i-2]
 * 如果该字符和前一个字符可以组成一个合法的字母序列（也就是组合起来是位于[10,26]之间的数），那么就存在两种情况：
 * 第一种：将该字符单独作为一个字母生效，那么能够产生的组合个数就是：直到前一个字符能够产生的组合个数，即dp[i-1]
 * 第二种：将该字符和前一个字符组合起来作为一个字母生效，那么能够产生的组合个数就是：直到前一个字符的前一个字符能够产生的组合个数，即dp[i-2]
 * 
 * 将两种组合个数加在一起就是直到该字符为止能够产生的组合个数
 * 初始化条件：dp[0] = 1, dp[1] = 1
 * 
 * 由于整个过程中只需要使用到当前字符的前两个位置能够产生的组合个数，所以可以将dp数组改成两个变量，就可以将O(n)的空间复杂度降到O(1)
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

int numDecodings(string s) {
    if (s.empty() || s[0] == '0') {
        return 0;
    }
    int dp_pre_pre = 1;
    int dp_pre = 1;
    int cur = 0;

    for (int i = 2; i < s.length() + 1; i++) {
        // 当前位置不为0，表明可以单独生成字母
        if (s[i - 1] != '0') {
            cur += dp_pre;
        }
        // 前一个字符和当前字符加在一起之后组成的整数在[10,26]之间，表明可以组合生成字母
        if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6') {
            cur += dp_pre_pre;
        }
        dp_pre_pre = dp_pre;
        dp_pre = cur;
        cur = 0;
    }
    return dp_pre;
}

int str2int(const string &);
/*
 * 返回组合总数的同时，计算出所有的组合情况
 * 参照上述动态规划的思路，维护一个结果数组：
 * 第一种情况中：i 位置单独生成字母，需要加上 i-1 生成的组合个数
 * 所以 i 位置产生的所有组合是在 i-1 位置产生的组合后加上当前字符所对应的字母
 * 
 * 第二种情况中：i 位置和 i-1 位置组合生成字母，需要加上 i-2 生成的组合个数
 * 所以 i 位置产生的所有组合是在 i-2 位置产生的所有组合后加上当前字符所对应的字母
 */
int numDecodings_with_res(string s) {
    if (s.empty() || s[0] == '0') {
        return 0;
    }
    // 数 --> 字母 的映射关系
    unordered_map<string, string> dig2let;
    int k = 65;
    for (int i = 1; i <= 27; ++i) {
        dig2let[to_string(i)] = char(k++);
    }

    int dp_pre_pre = 1;
    int dp_pre = 1;
    int cur = 0;

    vector<string> tmp_str1 = {""};
    vector<string> tmp_str2 = {dig2let[s.substr(0, 1)]};
    vector<string> cur_str;

    for (int i = 2; i < s.length() + 1; i++) {
        if (s[i - 1] != '0') {
            cur += dp_pre;
            // 对 i-1 生成的组合中加上当前字符对应的字母
            for (auto item : tmp_str2) {
                cur_str.push_back(item + dig2let[s.substr(i-1, 1)]);
            }
        }
        if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] <= '6') {
            cur += dp_pre_pre;
            // 对 i-2 生成的组合中加上 i-1 和 i 组合对应的字母
            for (auto item : tmp_str1) {
                cur_str.push_back(item + dig2let[s.substr(i-2, 2)]);
            }
        }
        dp_pre_pre = dp_pre;
        dp_pre = cur;
        cur = 0;

        tmp_str1 = tmp_str2;
        tmp_str2 = cur_str;
        cur_str.clear();
    }

    for (auto item : tmp_str2) {
        cout << item << " ";
    }
    return dp_pre;
}

int str2int(const string &str) {
    istringstream iss(str);
    int res;
    iss >> res;
    return res;
}

int main() {
    string str = "226"; // 2,26 -> BZ  2,2,6 -> BBF  22,6 -> VF
    auto ret = numDecodings(str);
    cout << ret << endl;
    numDecodings_with_res(str);
    return 0;
}