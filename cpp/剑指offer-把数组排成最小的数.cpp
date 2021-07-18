/*
 * 题意：
 * 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
 * 例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。
 *
 * 思路：
 * 1. 求出数组中所有数的全排列，拼接起来求最小即可。
 * 2. 使用排序规则来解题
 * 题意其实是希望找到一个排序的规则，使得数组按这个规则排序后，拼接在一起能排成最小的数。
 * 要确定排序规则，就是要确定两个数的大小，此时比大小不是数值的大小比较，而是确定哪个数应该排在前面
 * 根据要求两个数a和b能拼成ab和ba，如果ab<ba，那么a就应该排在b的前面。
 * 所以只需要定义一个排序方法即可。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 该方法作为一个参数传入到sort中：当认为a应该大于b时，返回true
static bool func(int a, int b) {
    string ab = to_string(a) + to_string(b);
    string ba = to_string(b) + to_string(a);
    // 相同位数的string进行比较是根据asc码来比较的
    return (ab < ba);
}

string PrintMinNumber(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), func);

    string ret = "";
    // 按顺序拼接即可
    for (auto num : numbers) {
        ret.append(to_string(num));
    }
    return ret;
}

int main() {
    vector<int> input = {3,32,321}; // 321 32 3
    auto ret = PrintMinNumber(input);
    cout << ret << endl;

    return 0;
}
