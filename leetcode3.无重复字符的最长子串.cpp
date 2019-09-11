/*
 * 题意：
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 *
 * 思路：
 * 滑动窗口方法
 * 用一个set存储滑动窗口[i, j]中的字符
 * 向右滑动索引j，如果它所指向的字符不在set中，就继续滑动j，每一次更新全局最长长度
 * 直到set中包含j所指向的字符时，就将索引i进行右滑
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
        return 0;
    }
    int len = s.length();
    unordered_set<char> cset;
    int i = 0, j = 0;
    int res = INT_MIN;
    while (j < len && i <= j) {
        if (cset.count(s[j]) == 0) {
            cset.insert(s[j]);
            ++j;
            res = max(res, j - i);
        } else {
            cset.erase(s[i]);
            ++i;
        }
    }
    return res;
}

int main() {
    string str = "abcabcbb";
    auto ret = lengthOfLongestSubstring(str);
    cout << ret << " ";
    return 0;
}