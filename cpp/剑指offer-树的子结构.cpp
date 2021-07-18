/*
 * 题目：
 * 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
 *
 * 思路：
 * 分为两步：
 * 1. 首先在树A中找一个结点R，R的值和树B根节点的值相等
 * 2. 判断树A中以R为根节点的子树是否和树B的结构一样（递归判断）
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool check(TreeNode* pRoot1, TreeNode* pRoot2) {
    // 子树遍历完成
    if (!pRoot2) {
        return true;
    }
    if (!pRoot1) {
        return false;
    }
    if (pRoot1->val != pRoot2->val) {
        return false;
    }
    return check(pRoot1->left, pRoot2->left) && check(pRoot1->right, pRoot2->right);
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
    if (pRoot2 == NULL || pRoot1 == NULL) {
        return false;
    }
    bool result = false;
    if (pRoot1->val == pRoot2->val) {
        result = check(pRoot1, pRoot2);
    }
    if (!result) {
        result = HasSubtree(pRoot1->left, pRoot2);
    }
    if (!result) {
        result = HasSubtree(pRoot1->right, pRoot2);
    }
    return result;
}

int main() {
    TreeNode* node1 = new TreeNode(8);
    TreeNode* node2 = new TreeNode(8);
    TreeNode* node3 = new TreeNode(7);
    TreeNode* node4 = new TreeNode(9);
    TreeNode* node5 = new TreeNode(2);
    TreeNode* node6 = new TreeNode(4);
    TreeNode* node7 = new TreeNode(7);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node5->left = node6;
    node5->right = node7;

    TreeNode* node8 = new TreeNode(8);
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node10 = new TreeNode(2);

    node8->left = node9;
    node8->right = node10;

    auto ret = HasSubtree(node1, node8);
    cout << ret;
    return 0;
}
