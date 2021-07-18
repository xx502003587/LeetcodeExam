/*
 * 题意：
 * 统计一个数字k在排序数组中出现的次数。
 *
 * 思路：
 * 1. 时间复杂度为O(n)的解法————直接遍历
 * 2. 时间复杂度为O(logn)的解法————二分法
 * 考虑到数组为已排序状态，所以可以利用该特性来进行解题
 * 如果可以找到 k 在数组中第一次出现和最后一次出现的下标索引，则可以直接计算次数 = 差值+1
 * 
 * 寻找k在数组中第一次出现的下标时
 * 利用二分法，每次找到数组中间的元素，
 * ————如果该元素等于k，先判断该元素是否为数组的第一个元素，如果是直接返回索引；
 * 否则判断前一个元素是否也等于k，如果等于则表明第一次出现的k在数组的左半部分中，直接修改右端点进行递归
 * ————如果该元素大于k或者小于k，直接修改端点进行递归
 * 
 * 寻找k在数组中最后一次出现的下标时，与上述同理
 */

#include <iostream>
#include <vector>

using namespace std;

int get_first_k(const vector<int>& data, int k, int start, int end) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    int value = data[mid];
    if (value == k) {
        // 如果这个中间值是第一个元素，或者这个值前一个元素不是k，直接返回索引
        if ((mid > 0 && data[mid-1] != k) || mid == 0) {
            return mid;
        } else {
            end = mid - 1;
        }
    } else if (value > k) {
        end = mid - 1;
    } else {
        start = mid + 1;
    }
    return get_first_k(data, k, start, end);
}

int get_last_k(const vector<int>& data, int k, int start, int end) {
    if (start > end) {
        return -1;
    }
    int mid = start + (end - start) / 2;
    int value = data[mid];
    if (value == k) {
        if ((mid < data.size() - 1 && data[mid+1] != k)
            || mid == data.size() - 1) {
            return mid;
        } else {
            start = mid + 1;
        }
    } else if (value > k) {
        end = mid - 1;
    } else {
        start = mid + 1;
    }
    return get_last_k(data, k, start, end);
}

int GetNumberOfK(vector<int> data ,int k) {
    if (data.empty()) {
        return 0;
    }
    int first = get_first_k(data, k, 0, data.size() - 1);
    int last = get_last_k(data, k, 0, data.size() - 1);
    if (first > -1 && last > -1) {
        return last - first + 1;
    }
    return 0;
}

int main() {
    vector<int> input = {1,2,3,3,3,3,4,5};
    auto ret = GetNumberOfK(input, 3);
    cout << ret << endl;
    return 0;
}
