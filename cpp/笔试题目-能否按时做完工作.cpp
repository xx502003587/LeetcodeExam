/*
 * 题意：
 * n个工作，第i个工作需要耗费ai单位时间，每个工作必须在bi时间点前完成
 * 给定n个工作所耗费的时间和截止时间点，判断从0时刻开始，给定的工作是否能够全部完成？
 * 如 (ai, bi) = (2,4), (1,9), (1,8), (4,9), (3,12)，按照顺序依次做每个工作即可完成
 * 
 * 思路：
 * ai表示耗费的时间，bi表示截止时间点，那么bi-ai就表示该工作做完之后距离deadline还有多久
 * 按照deadline从小到大进行排序，优先做间隔时间短的，然后做间隔时间长的，判断每一个工作昨晚是否超过了截止时间点
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& t1, const pair<int, int>& t2) {
    if (t1.second - t1.first < t2.second - t2.first) {
        return true;
    }
    return false;
}

bool judge(vector<pair<int, int>>& time) {
    int t = 0;
    for (auto pair : time) {
        // 做完当前工作后的时间点
        t += pair.first;
        if (t <= pair.second) {
            continue;
        } 
        // 如果超过截止时间点，说明不能做完
        else {
            return false;
        }
    }
    return true;
}

int main() {
    vector<pair<int, int>> time = {{2,4}, {1,9}, {1,8}, {4,9}, {3,12}};
    // 按照bi-ai从小到大排序，值越小表明工作优先级越高
    sort(time.begin(), time.end(), compare);

    if (judge(time)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
