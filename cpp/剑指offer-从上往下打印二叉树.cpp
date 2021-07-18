/*
 * 题意：
 * 从上往下打印出二叉树的每个节点，同层节点从左至右打印。
 *
 * 思路：
 * 利用队列即可很快解决
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> PrintFromTopToBottom(TreeNode* root) {
    vector<int> ret;
    if (!root) {
        return ret;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* tmp = q.front();
        q.pop();

        ret.push_back(tmp->val);
        if (tmp->left) {
            q.push(tmp->left);
        }
        if (tmp->right) {
            q.push(tmp->right);
        }
    }
    return ret;
}

int main() {
    TreeNode* node1 = new TreeNode(8);
    TreeNode* node2 = new TreeNode(6);
    TreeNode* node3 = new TreeNode(10);
    TreeNode* node4 = new TreeNode(5);
    TreeNode* node5 = new TreeNode(7);
    TreeNode* node6 = new TreeNode(9);
    TreeNode* node7 = new TreeNode(11);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    auto ret = PrintFromTopToBottom(node1);
    for (auto item : ret) {
        cout << item << " ";
    }

    return 0;
}
