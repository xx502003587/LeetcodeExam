/*
 * 题意：
 * 从扑克牌中随机抽5张，判断是不是一个顺子，即是不是连续的。
 * 2-10为本身，A为1，J为11，Q为12，K为13，大小王可以看成任何数
 *
 * 思路：
 * 首先对数组进行排序，排序后首先计算0的个数，然后再计算比0大的数中的间隔个数
 * 如果0的个数比间隔的个数少，那就无法构成连续序列，反之可以
 */

#include <iostream>
#include <vector>

using namespace std;

bool IsContinuous(vector<int> numbers) {
    if (numbers.empty()) {
        return false;
    }
    sort(numbers.begin(), numbers.end());
    int num_of_zero = 0;
    int index = 0;
    for (; index < numbers.size(); ++index) {
        if (numbers[index] == 0) {
            ++num_of_zero;
        } else {
            break;
        }
    }
    int big = index + 1;
    int num_of_gap = 0;
    while (big < numbers.size()) {
        if (numbers[index] == numbers[big]) {
            return false;
        }
        num_of_gap += numbers[big] - numbers[index] - 1;
        index = big;
        big++;
    }
    return (num_of_gap <= num_of_zero);
}

int main() {
    vector<int> input = {3, 4, 5, 1, 0};
    auto ret = IsContinuous(input); // cdefgab
    cout << ret << endl;
    return 0;
}
