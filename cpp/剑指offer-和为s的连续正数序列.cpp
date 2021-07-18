/*
 * 题意：
 * 输出所有和为S的连续正数序列。
 * 序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
 *
 * 思路：
 * 利用滑动窗口来解题
 * 维护两个指针，将两个指针之间的所有数之和为当前的sum值作比较
 * 如果和比sum大，则将左指针右移，减少区间内的数
 * 如果和比sum小，则将右指针右移，增加区间内的数
 * 如果和与sum相等，则将当前左右指针之间的数加入结果集
 */

#include <iostream>
#include <vector>

using namespace std;

// 将 left ~ right 之间的数加入结果集
void add_num(int left, int right, vector<vector<int>>& ret) {
    vector<int> tmp;
    for (int i = left; i <= right; i++) {
        tmp.push_back(i);
    }
    ret.push_back(tmp);
}

vector<vector<int> > FindContinuousSequence(int sum) {
    vector<vector<int>> ret;
    if (sum < 3) {
        return ret;
    }
    int left = 1, right = 2;
    int mid = (sum + 1) / 2;
    int cursum = left + right;
    // 循环的结束条件为 left < (sum + 1) / 2
    // 因为序列至少要包含两个数，所以当left到达 (sum+1)/2 时，再加后面的数就超过sum了
    while (left < mid) {
        // 当前窗口内的和大于sum时，一直将左指针右移
        while (cursum > sum) {
            cursum -= left;
            ++left;
        }
        // 当窗口内的和不大于sum时，判断如果相等且至少两个数，就加入结果集
        if (cursum == sum && left < right) {
            add_num(left, right, ret);
        }
        // 右指针右移，继续判断
        ++right;
        cursum += right;
    }
    return ret;
}

int main() {
    int s = 15;
    auto ret = FindContinuousSequence(s); // {1,2,3,4,5} {4,5,6} {7,8}
    for (auto out : ret) {
        for (auto in : out) {
            cout << in << " ";
        }
        cout << endl;
    }
    return 0;
}
