/*
 * 题意：
 *
 *
 * 思路：
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

// string转int
int str2int(const string& str) {
    istringstream iss(str);
    int res;
    iss >> res;
    return res;
}

// split函数，按照字符进行分割
vector<int> split(const string& str, const char& flag = ' ') {
    vector<int> res;
    istringstream ss(str);
    string temp = "";
    while (getline(ss, temp, flag)) {
        res.push_back(str2int(temp));
    }
    return res;
}

int main() {

    return 0;
}
