/*
 * 题意：
 * 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符
 * 并返回它的位置, 如果没有则返回 -1（需要区分大小写）.
 *
 * 思路：
 * 扫描两遍字符串
 * 第一次扫描时使用map存储不同字符出现的次数
 * 第二次扫描判断如果出现次数为1，直接返回
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int FirstNotRepeatingChar(string str) {
    unordered_map<char, int> ret;
    for (auto ch : str) {
        if (ret.count(ch) == 0) {
            ret[ch] = 1;
        } else {
            ++ret[ch];
        }
    }
    for (int i = 0; i < str.length(); ++i) {
        if (ret[str[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    string str = "abaccdeff";
    auto ret = FirstNotRepeatingChar(str);
    cout << ret << endl;

    return 0;
}
