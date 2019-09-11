/*
 * 题意：
 * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。（至少重复两次）
 * 给定的字符串只含有小写英文字母，并且长度不超过10000。
 * 如：abcabcabcabc 可由子字符串 "abc" 重复四次构成，或者子字符串 "abcabc" 重复两次构成。
 * 
 * 思路：
 * 如果能够由一个子串重复多次构成，那么这个子串的长度就是这个字符串的周期
 * 周期的长度最短为1，最长为字符串长度的一半
 * 所以对周期进行枚举，判断按照每一个周期推算是否可以构成该字符串
 * 在数学中 周期的表达式为 f(x+t) = f(x)，对应的表达式应该为s[i] = s[i % t]
 */

#include <iostream>
#include <algorithm>

using namespace std;

bool repeatedSubstringPattern(string s) {
    int len = s.size(), i = 0, t = 0;
    for (t = 1; t <= len / 2; ++t) {
        // 字符串长度对周期取余不为0, 一定不为周期串
        if (len % t) 
            continue;    
        for (i = t; i < len; ++i) {
            if (s[i % t] != s[i]) {
                break;
            }
        }
        if (i == len)
            return true;
    }
    return false;
}

int main() {
    string str = "abcabcabcabc";
    auto ret = repeatedSubstringPattern(str);
    cout << ret << endl;
    return 0;
}