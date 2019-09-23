/*
 * 题意：
 * 给定两个表示复数的字符串。
 * 返回表示它们乘积的字符串。注意，根据定义 i2 = -1 。
 * 输入字符串将以 a+bi 的形式给出，其中整数 a 和 b 的范围均在 [-100, 100] 之间。输出也应当符合这种形式。
 * 
 * 思路：
 *
 */

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

// string转int
int str2int(const string& str) {
    istringstream iss(str);
    int res;
    iss >> res;
    return res;
}

// split函数，按照字符进行分割
vector<string> split(const string& str, const char& flag = ' ') {
    vector<string> res;
    istringstream ss(str);
    string temp = "";
    while (getline(ss, temp, flag)) {
        if (!temp.empty())
            res.push_back(temp);
    }
    return res;
}

string complexNumberMultiply(string a, string b) {
    auto va = split(a, '+');
    va[1] = va[1].substr(0, va[1].length()-1);
    auto vb = split(b, '+');
    vb[1] = vb[1].substr(0, vb[1].length()-1);

    int part1 = str2int(va[0]) * str2int(vb[0]);
    int part2 = str2int(va[0]) * str2int(vb[1]) + str2int(va[1]) * str2int(vb[0]);
    int part3 = 0 - str2int(va[1]) * str2int(vb[1]);


    return to_string(part1+part3) + "+" + to_string(part2) + "i";
}

int main() {
    string a = "1+-1i";
    string b = "1+-1i";
    auto ret = complexNumberMultiply(a, b);
    cout << ret;
    return 0;
}
