/*
 * 题意：
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 *
 * 思路：
 * 回文串的长度有奇数和偶数之分
 * 奇数长度的回文串，如abcba，可以看做是从中间的字符用相同的字符向两边延伸相同的长度生成的
 * 偶数长度的回文串，如abccba，可以看做是从中间的两个字符用相同的字符向两边延伸相同的长度生成的
 * 
 * 所以当判断一个字符串中最长的回文子串时，可以遍历每一个字符，然后从该字符开始按照偶数和奇数两种情况分别向两边延伸
 * 然后检查可以延伸出的最大长度，同时更新全局最大长度即可
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string longestPalindromeStr(string s, int len, int left, int right) {
    // 如果left和right指向的字符相同，则回文串的长度+2
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    // 直到left和right指向的字符不同时，返回两个索引之间的部分
    return s.substr(left+1, right-left-1);
}

string longestPalindrome(string s) {
    int len = s.length();
    if (len <= 1) {
        return s;
    }
    int maxres = 1;
    string maxstr = s.substr(0,1);
    for (int i = 0; i < len; i++) {
        // 奇数情况  以第i个位置为中间的字符，从i索引开始向左延伸，从i索引开始向右延伸
        string oddstr = longestPalindromeStr(s, len, i, i);
        // 偶数情况  以第i和第i+1个位置为中间的字符，从i索引开始向左延伸，从i+1索引开始向右延伸
        string evenstr = longestPalindromeStr(s, len, i, i+1);
        // 两种情况中的较大者
        string max_len_str = oddstr.length() > evenstr.length() ? oddstr : evenstr;
        // 更新全局最大值
        if (max_len_str.length() > maxres) {
            maxres = max_len_str.length();
            maxstr = max_len_str;
        }
    }
    return maxstr;
}



int main() {
    string str = "babad";
    auto ret = longestPalindrome(str);
    cout << ret << " ";

    return 0;
}