/*
 * 题意：
 * 序列化二叉树的一种方法是使用前序遍历。
 * 当我们遇到一个非空节点时，我们可以记录下这个节点的值。
 * 如果它是一个空节点，我们可以使用一个标记值记录，例如 #
 * 例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。
 * 给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。
 * 每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。
 * 你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。
 *
 * 思路：
 * 由于遍历序列是前序遍历，所以对节点的访问顺序是中——左——右
 * 根据该特性，维护一个栈，从后向前遍历字符串，当遍历到一个#时，说明该节点只能是一个叶子节点，所以直接压栈
 * 当遍历到一个数时，表明栈顶已经存了该节点的两个子节点，所以将栈顶的两个节点出栈，并将当前数压栈（因为当前数还是其他节点的子节点）
 * 如果在出栈时发现栈中元素少于2个，说明序列是错误的，直接返回false
 * 如果将字符串遍历完之后，发现栈中只有一个元素（根节点），说明序列是正确的。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>

using namespace std;

vector<string> split(const string& str, const char& flag = ' ') {
    vector<string> res;
    istringstream ss(str);
    string temp;
    while (getline(ss, temp, flag)) {
        res.push_back(temp);
    }
    return res;
}

bool isValidSerialization(string preorder) {
    stack<string> s;
    auto seq = split(preorder, ',');
    for (int i = seq.size() - 1; i >= 0; --i) {
        if (seq[i] == "#") {
            s.push(seq[i]);
        } else {
            if (s.size() < 2) {
                return false;
            } else {
                s.pop();
                s.pop();
                s.push(seq[i]);
            }
        }
    }
    if (s.size() == 1) {
        return true;
    }
    return false;
}

int main() {
    string str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    auto ret = isValidSerialization(str);
    cout << ret;

    return 0;
}