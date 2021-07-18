/*
 * 题意：
 * 给出一个区间的集合，请合并所有重叠的区间。
 *
 * 思路：
 * 首先将区间按照start从小到大的顺序进行排序
 * 从第二个区间开始考虑，如果当前区间
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() <= 1) {
        return intervals;
    }

    std::sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    for (auto v : intervals) {
        if (res.empty() || res.back()[1] < v[0]) {
            res.push_back(v);
        } else {
            res.back()[1] = max(res.back()[1], v[1]);
        }
    }
    return res;
}

int main() {
    vector<vector<int>> nums = {{1,3},{2,6},{8,10},{15,18}};
    auto ret = merge(nums);
    for (auto out : ret) {
        for (auto in : out) {
            cout << in << " ";
        }
        cout << endl;
    }
    return 0;
}
