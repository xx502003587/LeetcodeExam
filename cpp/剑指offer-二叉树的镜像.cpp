/*
 * 题目：
 * 操作给定的二叉树，将其变换为源二叉树的镜像。
 *
 * 思路：
 * 递归解决
 * 如果当前节点为空、或者当前节点的左右子树都为空，则返回
 * 将当前节点的左右子树互换，然后对不空的左右子树进行递归
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Mirror(TreeNode *pRoot) {
    if (pRoot == NULL) {
        return;
    }
    if (pRoot->left == NULL && pRoot->right == NULL) {
        return;
    }
    // 交换两个子树
    TreeNode* tmp;
    tmp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = tmp;
    // 递归子树
    if (pRoot->left) {
        Mirror(pRoot->left);
    }
    if (pRoot->right) {
        Mirror(pRoot->right);
    }
}

// 输出中序遍历序列
void print_inorder(TreeNode* iter) {
    if (!iter) {
        return;
    }
    print_inorder(iter->left);
    cout << iter->val << " ";
    print_inorder(iter->right);
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

    cout << "转换前二叉树中序遍历序列为：";
    print_inorder(node1);
    cout << endl;

    Mirror(node1);
    cout << "转换后二叉树中序遍历序列为：";
    print_inorder(node1);

    return 0;
}
