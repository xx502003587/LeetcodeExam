/*
 * 题意：
 * 一本字典中，每个单词都只由a和b两个字母组成，且每个单词中a出现的次数不超过n个，b出现的次数不超过m个
 * 找出按照字典序排序的第k个单词
 * 如a-2 b-1，求第4个，所有单词为:a, aa, aab, ab, aba, b, ba, baa 第4个为ab
 *
 * 思路：
 * 回溯法
 * 由于要按照字典序排列，a应该排在b之前，所以当a的使用次数没有超过n个时，就可以一直往字符串后面添加a，每添加一个就是一个单词
 * 当a的使用次数等于n时，就在其后面继续添加b
 * 当a和b的使用次数都到达上限时，开始回溯
 * 维护一个索引，判断是否查找到第k个，如果查找到第k个，就中断搜索
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void func(string &ret, int an, int bn, int cura, int curb, int k, int& curk) {
    if (curk == -1) {
        return;
    }
    // 如果 a b 使用次数都到达上限，输出，并对curk加1，返回
    if (an <= cura && bn <= curb) {
        curk++;
        if (curk >= k) {
            cout << "curk=" << curk << "\t" <<ret  << endl;
            curk = -1;
        }
        return;
    }
    // 首先输出递归到当前步骤的ret
    if (!ret.empty()) {
        curk++;
        if (curk >= k) {
            cout << "curk=" << curk << "\t" <<ret  << endl;
            curk = -1;
        }
    }
    // 如果a没用完，就在后面加一个a 递归
    if (an > cura) {
        ret.append(1, 'a');
        func(ret, an, bn, cura + 1, curb, k, curk);
        if (curk == -1) {
            return;
        }
        // 为了保证下一轮正常回溯，要把加的a去掉
        ret.pop_back();
    }
    // 如果b没用完，就在后面加一个b 递归
    if (bn > curb) {
        ret.append(1, 'b');
        func(ret, an, bn, cura, curb + 1, k, curk);
        if (curk == -1) {
            return;
        }
        // 为了保证下一轮正常回溯，要把加的b去掉
        ret.pop_back();
    }
}

int main() {
    // a b最多出现的次数
    int an = 2, bn = 1;
    int k = 4;
    string ret = "";
    // 当前计算到第几个
    int cnt = 0;
    func(ret, an, bn, 0, 0, k, cnt);

    return 0;
}