/*
 * 题意：
 * 在《英雄联盟》的世界中，有一个叫 “提莫” 的英雄，他的攻击可以让敌方英雄艾希进入中毒状态。
 * 现在，给出提莫对艾希的攻击时间序列和提莫攻击的中毒持续时间，你需要输出艾希的中毒状态总时长。
 * 你可以认为提莫在给定的时间点进行攻击，并立即使艾希处于中毒状态。
 * 
 * 思路：
 * 如果从 timeSeries[i] 开始攻击，加上持续时间 duration 后，还没达到 timeSeries[i+1] 的时间点
 * 说明本次中毒的持续时间是满的
 * 
 * 如果从 timeSeries[i] 开始攻击，加上持续时间 duration 后，已经超过了 timeSeries[i+1] 的时间点
 * 说明本次中毒的持续时间只从 timeSeries[i] 持续到 timeSeries[i+1] ，而 timeSeries[i+1] 重新攻击后，将刷新持续时间
 * 
 * 所以分这两种情况来进行累加求和即可
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    if (timeSeries.empty()) {
        return 0;
    }
    int res = 0;
    int len = timeSeries.size();
    for (int i = 0; i < len - 1; ++i) {
        // 加上持续时间后没到达下一次攻击的时间，直接加上持续时间
        if (timeSeries[i] + duration < timeSeries[i+1]) {
            res += duration;
        } 
        // 超过了下一次攻击的时间点，直接加上时间差
        else {
            res += timeSeries[i+1] - timeSeries[i];
        }
    }
    return res + duration;
}

int main() {
    vector<int> timeSeries = {1,4};
    int duration = 2;
    auto ret = findPoisonedDuration(timeSeries, duration); // 4
    cout << ret;
    return 0;
}
