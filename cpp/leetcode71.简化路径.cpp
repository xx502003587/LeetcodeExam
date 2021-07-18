/*
 * 题意：
 * 以 Unix 风格给出一个文件的绝对路径，你需要简化它。或者换句话说，将其转换为规范路径。
 * 在 Unix 风格的文件系统中，一个点（.）表示当前目录本身；此外，两个点 （..） 表示将目录切换到上一级（指向父目录）；两者都可以是复杂相对路径的组成部分。
 * 请注意，返回的规范路径必须始终以斜杠 / 开头，并且两个目录名之间必须只有一个斜杠 /。
 * 最后一个目录名（如果存在）不能以 / 结尾。此外，规范路径必须是表示绝对路径的最短字符串。
 * 如："/a//b////c/d//././/.." 输出 "/a/b/c"
 *
 * 思路：
 * 文件夹的打开过程相当于一个路径放入栈中的步骤
 * 打开一个文件夹就是向栈顶压入一个路径，后退就是弹出栈顶路径
 * 根据这个思路进行解题
 * 
 * 首先使用分割函数将多余的 / 都去掉
 * 遍历整个路径序列：
 * 遇到 . 不做任何操作
 * 遇到 .. 如果栈不空，弹出栈顶元素；否则不做任何操作，表示已经到达根目录，无法再向上一级跳跃
 * 遇到路径直接压栈
 * 
 * 遍历完序列之后，栈中剩下的就是最后的路径序列的倒序，只需倒序输出并使用 / 进行分隔即可
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

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

string simplifyPath(string path) {
    // 根据 / 对序列进行划分，得到每个路径名称
    auto ret = split(path, '/');

    stack<string> s;
    for (auto item : ret) {
        // 遇到 . 表示停留在当前目录，不做任何操作
        if (item == ".") {
            continue;
        } 
        // 遇到 .. 表示返回上一级目录
        else if (item == "..") {
            // 如果栈不空，直接弹出栈顶元素。如果栈空表示当前路径已经是根目录，无法向上级跳跃
            if (!s.empty()) {
                s.pop();
            }
        } 
        // 遇到路径直接压栈
        else {
            s.push(item);
        }
    }

    string val = "";
    // 从栈顶到栈底是路径的反向序列，输出时使用前插法即可得出路径序列
    while (!s.empty()) {
        val.insert(0, "/" + s.top());
        s.pop();
    }
    // 如果输出序列为空 表示为根目录，应该将其改成 "/"
    if (val.empty()) {
        val = "/";
    }
    return val;
}

int main() {
    string path = "/home/";
    auto val = simplifyPath(path);
    cout << val;

    return 0;
}