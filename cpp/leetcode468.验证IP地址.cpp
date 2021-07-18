/*
 * 题意：
 * 编写一个函数来验证输入的字符串是否是有效的 IPv4 或 IPv6 地址。
 * IPv4 地址由十进制数和点来表示，每个地址包含4个十进制数，其范围为 0 - 255， 用(".")分割。比如，172.16.254.1
 * 同时，IPv4 地址内的数不会以 0 开头。比如，地址 172.16.254.01 是不合法的。
 * 
 * IPv6 地址由8组16进制的数字来表示，每组表示 16 比特。这些组数字通过 (":")分割。比如,  2001:0db8:85a3:0000:0000:8a2e:0370:7334 是一个有效的地址。而且，我们可以加入一些以 0 开头的数字，字母可以使用大写，也可以是小写。所以， 2001:db8:85a3:0:0:8A2E:0370:7334 也是一个有效的 IPv6 address地址 (即，忽略 0 开头，忽略大小写)。
 * 然而，我们不能因为某个组的值为 0，而使用一个空的组，以至于出现 (::) 的情况。 比如， 2001:0db8:85a3::8A2E:0370:7334 是无效的 IPv6 地址。
 * 同时，在 IPv6 地址中，多余的 0 也是不被允许的。比如， 02001:0db8:85a3:0000:0000:8a2e:0370:7334 是无效的。
 * 
 * 说明: 你可以认为给定的字符串里没有空格或者其他特殊字符。
 *
 * 思路：
 * 根据地址的规则来进行判断
 * 
 * 1. 判断是否ipv4地址
 * 首先根据 . 分割字符串后，如果不是4个子串，错误。
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

// string转int
int str2int(const string &str) {
    istringstream iss(str);
    int res;
    iss >> res;
    return res;
}

// split函数，按照字符进行分割
vector<string> split(const string &str, const char &flag = ' ') {
    vector<string> res;
    istringstream ss(str);
    string temp = "";
    while (getline(ss, temp, flag)) {
        res.push_back(temp);
    }
     if (!res.empty() && str.back() == flag) {
         res.emplace_back("");
     }
    return res;
}

bool isValidIPv4(string IP) {
    auto ipv4 = split(IP, '.');
    if (ipv4.size() != 4) {
        return false;
    }
    for (auto &ip : ipv4) {
        if (ip.empty() || (ip.length() > 1 && ip[0] == '0') || ip.length() > 3) {
            return false;
        }
        for (auto &ch : ip) {
            if (!isdigit(ch)) {
                return false;
            }
        }
        int num = str2int(ip);
        if (num < 0 || num > 255) {
            return false;
        }
    }
    return true;
}

bool isValidIPv6(string IP) {
    auto ipv6 = split(IP, ':');
    if (ipv6.size() != 8) {
        return false;
    }
    for (auto &ip : ipv6) {
        if (ip.empty() || ip.length() > 4) {
            return false;
        }
        for (auto ch : ip) {
            if (!(isdigit(ch) || (ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F'))) {
                return false;
            }
        }
    }
    return true;
}

string validIPAddress(string IP) {
    if (isValidIPv4(IP)) {
        return "IPv4";
    }
    if (isValidIPv6(IP)) {
        return "IPv6";
    }
    return "Neither";
}

int main() {
    vector<string> strs = {"172.16.254.1", // "IPv4"
                           "172.16.254.01", // "Neither"
                           "2001:0db8:85a3:0:0:8A2E:0370:7334", // "IPv6"
                           "256.256.256.256"}; // "Neither"
    for (auto test_case : strs) {
        cout << validIPAddress(test_case) << endl;
    }
    return 0;
}