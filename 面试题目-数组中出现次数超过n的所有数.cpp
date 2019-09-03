/*
 * 题意：
 * 给定一个有N个数的整型数组arr，给定整数K，求出现次数超过 N/K 的所有数
 * 限制条件：时间复杂度为O(n)，仅对数组进行一次遍历
 *
 * 思路：
 * 1. 遍历统计次数
 * 
 * 2. 根据抽屉原理来解题
 * 考虑一个数组a = [1,2,3,4,5,5,5,5,4,4,4,4]，N为12，K为5的情况：
 * 当一个数在数组中出现次数大于 N/K 时，如果每次都删除K个不相同的数，当数组中数的个数不足K时，这个数一定还存在于数组中
 * 在对数组的遍历过程中，一边遍历一边用map存储数字出现的次数，每当map的容量等于5时，就把每一个数出现的次数减1，如果某个数值为0则删除
 * 最后遍历完之后在map中存在的数就是次数超过N/K的数
 * 
 * 当K等于2时，就是查找出现次数超过一半的数
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    vector<int> num = {1,2,3,4,5,5,5,5,4,4,4,4};
    
    int times = 2;

    unordered_map<int, int> ret;
    for (auto item : num) {
        if (ret.count(item) == 0) {
            if (ret.size() == 4) {
                for (auto iter = ret.begin(); iter != ret.end();) {
                    iter->second -= 1;
                    if (iter->second == 0) {
                        ret.erase(iter++);
                    } else {
                        ++iter;
                    }
                }
            } else {
                ret[item] = 1;
            }
        } else {
            ret[item] += 1;
        }
    }

    cout << ret.size();

    return 0;
}

