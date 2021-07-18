/*
 * 题意：
 * 字符串 S 和 T 只包含小写字符。在 S 中，所有字符只会出现一次。
 * S 已经根据某种规则进行了排序。我们要根据 S 中的字符顺序对T进行排序。更具体地说，如果S中x在y之前出现，那么返回的字符串中x也应出现在y之前。
 * 返回任意一种符合条件的字符串T。
 *
 * 思路：
 * 三个步骤：
 * 1. 记录下T中出现的字符以及字符对应的次数k
 * 2. 从左往右遍历S中的每个字符，为了保证相同的顺序，如果当前字符在T中出现了的话，就将该字符输出k次，并更新T中该字符出现的次数为0
 * 3. 遍历完S后，将T中剩余的字符追加在后面即可
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string customSortString(string S, string T) {
    vector<int> tlet(26, 0);
    // 记录T字符串中不同字符对应的出现次数
    for (auto ch : T) {
        tlet[ch-97]++;
    }

    string ret = "";
    for (int i = 0; i < S.length(); ++i) {
        // 如果该字符在T中出现了，就将其复制对应的次数
        ret.append(tlet[S[i] - 97], S[i]);
        tlet[S[i] - 97] = 0;
    }
    // 处理没有在S中出现的那些字符
    for (int i = 0; i < tlet.size(); ++i) {
        if (tlet[i]) {
            ret.append(tlet[i], i+97);
        }
    }
    return ret;
}

int main() {
    string S = "cba", T = "abcd";
    cout << customSortString(S, T);
    return 0;
}
