/*
 * 题意：
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 如：{"eat", "tea", "tan", "ate", "nat", "bat"}
 * 分组结果为：["ate","eat","tea"], ["nat","tan"], ["bat"]
 * 
 * 思路：
 * 根据字母异位词的定义，如果一组词是字母异位词，那么这组词的排序结果应该是相同的
 * 维护一个map，键为某个排序结果，值为该排序结果所对应的所有词
 * 经过一次遍历之后就可以把对应的分组计算出来
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (auto str : strs) {
        auto tmp = str;
        // 按字母序排序
        sort(tmp.begin(), tmp.end());
        // 如果map中没有这个key，就加进去
        if (m.count(tmp) == 0) {
            m[tmp] = vector<string>();
        }
        // 将当前词加入到它所对应的key中去
        m[tmp].push_back(str);
    }

    // 拿到每个key对应的value数组，就是最后的结果集
    vector<vector<string>> ret;
    for (auto iter = m.begin(); iter != m.end(); ++iter) {
        ret.push_back(iter->second);
    }
    return ret;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ret = groupAnagrams(strs); // ["ate","eat","tea"], ["nat","tan"], ["bat"]
    for (auto out : ret) {
        for (auto in : out) {
            cout << in << " ";
        }
        cout << endl;
    }
    return 0;
}