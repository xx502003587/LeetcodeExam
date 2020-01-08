/*
 * 题意：
 * 二叉树的序列化和反序列化
 *
 * 思路：
 * 序列化：
 * 使用先序遍历对整棵树进行遍历
 * 如果遍历到某个节点不为空，则将其val加入到字符串中；如果为空，则将null加入字符串中
 *
 * 反序列化：
 * 根据先序序列，从字符串的前面向后遍历
 * 当遍历到的子串不为null时，则为一个非空节点；如果为null，则为空节点
 * 然后递归到两个子节点，当左子树完全建立起来之后，会自动地轨到右子树
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<string> split(const string& s, const char flag = ' ') {
    vector<string> v;
    istringstream iss(s);
    string temp;
    while (getline(iss, temp, flag)) {
        v.push_back(temp);
    }
    return v;
}

void helper1(TreeNode* root, string& str) {
    if (!root) {
        str += "null,";
    } else {
        str += to_string(root->val) + ",";
        helper1(root->left, str);
        helper1(root->right, str);
    }
}

// 序列化，树 -> 字符串
string serialize(TreeNode* root) {
    string str = "";
    helper1(root, str);
    str.pop_back();
    return str;
}

TreeNode* helper2(vector<string>& data, int& index) {
    if (data[index] == "null") {
        index++;
        return NULL;
    }

    TreeNode* root = new TreeNode(stoi(data[index]));
    index++;
    root->left = helper2(data, index);
    root->right = helper2(data, index);
    return root;
}

// 反序列化，字符串 -> 树
TreeNode* deserialize(string data) {
    vector<string> vs = split(data, ',');
    int index = 0;
    return helper2(vs, index);
}

int main() {
    auto node1 = new TreeNode(5);
    auto node2 = new TreeNode(4);
    auto node3 = new TreeNode(2);
    auto node4 = new TreeNode(3);
    auto node5 = new TreeNode(6);
    auto node6 = new TreeNode(8);

    node1->left = node2;
    node2->left = node3;
    node3->right = node4;
    node1->right = node5;
    node5->right = node6;
    auto ret = serialize(node1);
    cout << ret << endl;

    auto tmp = deserialize(ret);

    return 0;
}
