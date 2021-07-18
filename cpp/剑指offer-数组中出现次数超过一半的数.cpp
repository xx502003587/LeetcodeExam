/*
 * 题意：
 * 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 *
 * 思路：
 * 1. 排序后，统计每个数出现的次数
 * 2. 如果有一个数出现次数超过了长度的一半，那么在排序后这个数一定位于数组的中间，即中位数，即长度为n的数组中第n/2大的数
 * 3. 摩尔投票法
 * 如果一个数出现的次数超过了长度的一半，就是说它出现的次数比其他所有数出现的次数的和还要多。
 * 因此可以在遍历数组时保存两个值：一个是数组中的一个数，一个是次数。
 * 当遍历到下一个数的时候，如果下一个数和保存的数相同，给次数加1；如果不同，给次数减1。如果次数为0，将保存的数替换成下一个数，并将次数设置为1
 * 由于我们要找的数出现次数比其他所有数出现次数之和还要多，那么要找的数肯定是最后一次把次数设成1时对应的数（如果这个数的确存在的话）
 * 最后，找到这个数之后，还要遍历一次数组来判断这个数出现次数是否真的次数超过一半
 */

#include <iostream>
#include <vector>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
    if (numbers.empty()) {
        return 0;
    }
    int cur = numbers[0];
    int count = 1;

    for (int i = 1; i < numbers.size(); ++i) {
        // 如果count为0 则将保存的数替换为当前的数，并将count设为1
        if (count == 0) {
            count = 1;
            cur = numbers[i];
            continue;
        }
        if (numbers[i] == cur) {
            ++count;
        } else {
            --count;
        }
    }
    // 判断出现次数
    count = 0;
    for (auto num : numbers) {
        if (num == cur) {
            ++count;
        }
    }
    return (count > numbers.size()/2) ? cur : 0;
}

int main() {
    vector<int> positive = {1,2,3,2,2,2,5,4,2};
    auto ret = MoreThanHalfNum_Solution(positive);
    if (ret == 0) {
        cout << "没有出现次数超过一半的数" << endl;
    } else {
        cout << "出现次数超过一半的数是" << ret << endl;
    }

    vector<int> negative = {1,2,3,4,5};
    ret = MoreThanHalfNum_Solution(negative);
    if (ret == 0) {
        cout << "没有出现次数超过一半的数" << endl;
    } else {
        cout << "出现次数超过一半的数是" << ret << endl;
    }

    return 0;
}
