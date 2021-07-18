/*
 * 题意：
 * 给定两个数组，编写一个函数来计算它们的交集。
 * 
 * 要求：
 * 输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
 *
 * 思路：
 * 与leetcode349题思路基本类似，349题中map对第一个数组进行存储时value为1，表明该数存在于第一个数组中
 * 该题中value应该对第一个数组中数出现的次数进行计数
 * 
 * 使用一个map来记录第一个数组中每个数出现的次数
 * 遍历第二个数组，对于每个数判断是否存在于map中
 * 如果该数不存在于map中，表明第一个数组中不存在该数，跳过
 * 如果该数存在于map中，判断该数出现的次数，即value的值
 *     如果该值大于1，表明该数可以和第一个数组中的该数组成一对，将该数加入结果集，并将value值减1，表明从两个数组中同时删除该数后，第一个数组中还有该数存在
 *     如果该值等于1，表明在两个数组中最多还能组成一对，将该数加入结果集，并将map中该key删掉
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> m1;
    for (auto item : nums1) {
        if (m1.count(item) == 0) {
            m1[item] = 1;
        } else {
            m1[item]++;
        }
    }

    vector<int> result;
    for (auto item : nums2) {
        if (m1.count(item) == 0) {
            continue;
        } else {
            if (m1[item] == 1) {
                result.push_back(item);
                m1.erase(item);
            } else {
                result.push_back(item);
                m1[item]--;
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    auto ret = intersect(nums1, nums2); // 2,2
    for (auto num : ret) {
        cout << num << " ";
    }
    return 0;
}