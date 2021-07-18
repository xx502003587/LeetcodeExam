/*
 * 题意：
 * 给定一系列ip地址过滤规则，然后对输入的一部分ip地址判断是否需要被过滤
 * 过滤规则共分为3种：
 * 1. ip地址完全相同————如过滤规则为：222.205.58.16，那么ip地址222.205.58.16就应该被过滤
 * 2. ip地址前缀为*————如过滤规则为：*.58.16，那么ip地址222.205.58.16就应该被过滤
 * 3. ip地址后缀为*————如过滤规则为：224.*，那么ip地址224.205.58.16就应该被过滤
 *
 * 思路：
 * 按照规则判断即可
 * 将过滤规则和ip地址字符串通过 . 进行分割
 * 遍历每一个待判断ip地址，将其与规则库中的每一个规则进行匹配
 * 1. 如果两个字符串相等，说明符合第一种过滤规则，返回true
 * 2. 如果过滤规则的第一部分为 *，则从规则和待判断ip的最后一部分开始往前判断每一部分是否相等，当判断到过滤规则的*时，说明两者后面全部相同，返回true
 * 3. 如果过滤规则的最后一部分为 *，则从规则和待判断ip的第一个部分开始往后判断每一个部分是否相等，当判断到过滤规则的*时，说明两者前面全部相同，返回true
 * 
 * 如果遍历完所有的规则都不符合3个条件，说明不应该被过滤，返回false
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string str) {
    vector<string> ret;
    istringstream ss(str);
    string temp = "";
    while (getline(ss, temp, '.')) {
        ret.push_back(temp);
    }
    return ret;
}

bool judge_ip(const vector<string>& rule, string ip) {
    for (auto t : rule) {
        if (t.find("*") == string::npos) {
            if (ip == t) {
                return true;
            }
        } else {
            auto tvs = split(t);
            auto ipvs = split(ip);

            // 第一位为*
            if (tvs[0] == "*") {
                int tix = tvs.size() - 1;
                int ipix = ipvs.size() - 1;
                while (tvs[tix] == ipvs[ipix]) {
                    --tix;
                    --ipix;
                }
                if (tix == 0) {
                    return true;
                }
            }
            // 最后一位为*
            else {
                int ix = 0;
                while (tvs[ix] == ipvs[ix]) {
                    ++ix;
                }
                if (ix == tvs.size() - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<string> rule = {"222.205.58.16", "*.58.16", "222.205.58.*", "*.16", "224.*"};
    vector<string> judge = {"222.205.58.17", "222.205.59.19", "223.205.59.16"};

    for (auto ip : judge) {
        cout << judge_ip(rule, ip) << " "; // 1 0 1
    }
    return 0;
}