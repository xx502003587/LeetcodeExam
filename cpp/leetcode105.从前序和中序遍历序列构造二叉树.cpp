/*
 * 题意：
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 注意: 你可以假设树中没有重复的元素。
 *
 * 思路：
 * 先序遍历序列中，第一个元素是整棵树的根节点
 * 而在中序遍历序列中，这个根节点元素将序列分成了两部分，分别是整棵树左子树和右子树的元素节点
 * 由于先序序列是根-左-右的遍历顺序，所以先序序列的第二个元素就是左子树的根节点
 * 因此，可以维护一个全局递增的索引变量，当前索引指向的 preorder 中的元素就是当前递归过程中整棵树的根节点
 * 以此类推，只需要将先序遍历序列中的根节点删除，然后对左子树和右子树进行左右两个区间的递归即可
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 指向 preorder 中元素的索引，该索引指向的数总是当前递归时整棵树的根节点
int rootindex = 0;

// left 和 right 分别指向当前递归过程中，当前子树中所有元素在中序序列中的两个索引端点
TreeNode *helper(int left, int right, unordered_map<int, int> &umap,
                 vector<int> &preorder, vector<int> &inorder) {
    // 如果left和right指向同一个元素，表明当前节点是个空节点
    if (left == right) {
        return nullptr;
    }
    // 获得当前子树根节点的值，并将index加1
    int rootvalue = preorder[rootindex++];
    TreeNode *root = new TreeNode(rootvalue);
    // 找到根节点在中序序列中的索引
    int index = umap[rootvalue];
    // 索引左边的部分是左子树
    root->left = helper(left, index, umap, preorder, inorder);
    // 索引右边的部分是右子树
    root->right = helper(index + 1, right, umap, preorder, inorder);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    // 用一个map来记录 inorder 序列中元素和其下标的对应关系
    // 可以用来在找到根节点后，将中序序列分成左子树和右子树两个部分
    unordered_map<int, int> umap;
    int i = 0;
    for (auto n : inorder) {
        umap[n] = i++;
    }

    return helper(0, preorder.size(), umap, preorder, inorder);
}

void postorder(TreeNode *root) {
    if (!root) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    auto root = buildTree(preorder, inorder);
    postorder(root); // 9 15 7 20 3
    return 0;
}
