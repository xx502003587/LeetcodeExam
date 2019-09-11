/*
 * 题意：
 * 给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
 * num1 和num2 的长度都小于 5100.
 * num1 和num2 都只包含数字 0-9.
 * num1 和num2 都不包含任何前导零。
 * 你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
 *
 * 思路：
 * 利用最简单的列竖式计算加法的思路进行计算
 * 从最右边向左边计算对应位两个数字的和，统计进位，将当前位的值加入到结果中
 */

#include <iostream>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2) {
    if (num1 == "0")
        return num2;
    if (num2 == "0")
        return num1;

    int cur1 = num1.length() - 1;
    int cur2 = num2.length() - 1;
    int up = 0;
    string res = "";
    while (cur1 >= 0 || cur2 >= 0) {
        // 判断短的字符串是否已经计算完毕，如果计算完毕就赋值为0
        int n1 = cur1 >= 0 ? num1[cur1] - '0' : 0;
        int n2 = cur2 >= 0 ? num2[cur2] - '0' : 0;
        int sum = n1 + n2 + up;
        up = sum / 10;
        res.append(1, char((sum % 10) + '0'));
        cur1--;
        cur2--;
    }
    // 防止 1+9 跳出循环 等于0的情况
    if (up == 1) {
        res.append(1, '1');
    }
    // 加入结果集时是顺序添加的，所以输出结果需要倒序
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string num1 = "923";
    string num2 = "11111";
    cout << addStrings(num1, num2); // 12034
    return 0;
}