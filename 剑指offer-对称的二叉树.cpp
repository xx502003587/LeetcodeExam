/*
 * 题意：
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。
 * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 *
 * 思路：
 * 1. 递归法
 * 对于一个树来说，如果它是对称的，那么它的根节点的左子树应该和右子树镜像对称
 * 而当两棵树为镜像对称时，那么应该满足两个条件：
 * ————两个根节点具有相同的值
 * ————每个树的右子树都与另一棵树的左子树镜像对称
 * 所以可以用递归来解决。对每一个节点的两棵树来说，如果左右子树的值相同，并且左子树与右子树镜像对称，就是对称的。
 * 
 * 2. 迭代法
 * 使用队列来进行迭代，队列中每两个连续的节点应该是相等的，而且他们的子树互为镜像
 * 每次取两个节点比较他们的值，并将两个节点的左右子树按相反的顺序入队列。
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归法
bool isMirror(TreeNode* p1, TreeNode* p2) {
    // 两个子树都空，是镜像的
    if (p1 == NULL && p2 == NULL) {
        return true;
    }
    // 两个子树都不空的情况下，只有当值相同并且一棵树的左子树（右子树）和另一个棵树的右子树（左子树）镜像才成立
    if (p1 != NULL && p2 != NULL) {
        return (p1->val == p2->val) && isMirror(p1->left, p2->right)
               && isMirror(p1->right, p2->left);
    }
    return false;
}

bool isSymmetrical(TreeNode* pRoot) {
    // 传入根节点，如果根节点的左右子树是镜像的，这棵树就是对称的
    return isMirror(pRoot, pRoot);
}

// 迭代法
bool isSymmetrical(TreeNode* pRoot) {
        queue<TreeNode*> q;
        q.push(pRoot);
        q.push(pRoot);
        while (!q.empty()) {
            auto p1 = q.front();
            q.pop();
            auto p2 = q.front();
            q.pop();
            // 如果连续两个节点都为空，则继续迭代
            if (p1 == NULL && p2 == NULL) {
                continue;
            }
            // 如果只有一个为空，则不对称
            if (p1 == NULL || p2 == NULL) {
                return false;
            }
            // 如果两个节点的值不一样，则不对称
            if (p1->val != p2->val) {
                return false;
            }
            // 将左右子树按相反顺序入队列
            // 左子树的左子树应该和右子树的右子树相等
            q.push(p1->left);
            q.push(p2->right);
            // 左子树的右子树应该和右子树的左子树相等
            q.push(p1->right);
            q.push(p2->left);
        }
        return true;
    }

int main() {
    auto node1 = new TreeNode(8);
    auto node2 = new TreeNode(6);
    auto node3 = new TreeNode(6);
    auto node4 = new TreeNode(5);
    auto node5 = new TreeNode(7);
    auto node6 = new TreeNode(7);
    auto node7 = new TreeNode(5);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    cout << isSymmetrical(node1);
    return 0;
}
