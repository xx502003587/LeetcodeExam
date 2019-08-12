/*
 * 题目：
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
 * 例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
 * 
 * 思路：
 * 根据前序和中序序列的特性：前序的第一个数肯定为根节点，这个数在中序序列中将序列分成了左右两部分
 * 而这两个部分分别是根节点的左子树和右子树
 * 所以可以使用递归来解决这个问题
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 用一个全局变量来表示当前递归过程中的根节点对应的数组下标值
// 因为递归过程是先根再左后右，比如根节点时值为第1个，左子树为第2个，右子树为第3个，以此类推
int root_index = 0;

TreeNode* helper(int left, int right, unordered_map<int, int>& umap, vector<int>& pre, vector<int>& vin) {
    // 如果当前子树的中序序列左边界和右边界是同一个数，表明当前节点是一个空节点
    if (left == right) {
        return NULL;
    }
    // 获取当前子树根节点的值
    int root_value = pre[root_index++];
    auto root = new TreeNode(root_value);
    // 获取当前根节点值在中序序列中的位置
    int index = umap[root_value];
    // 位置左边从 left 到 index-1 为左子树的序列
    root->left = helper(left, index, umap, pre, vin);
    // 位置右边从 index+1 到 right-1 为右子树的序列
    root->right = helper(index+1, right, umap, pre, vin);
    return root;
}

TreeNode* reConstructBinaryTree(vector<int>& pre, vector<int>& vin) {
    unordered_map<int, int> umap;
    int i = 0;
    // 用一个map存储中序序列中每个值对应的数组下标，用于递归过程中找到当前根节点值对应的位置并用此位置将序列分成两半
    for (auto num : vin) {
        umap[num] = i++;
    }
    return helper(0, pre.size(), umap, pre, vin);
}

void print_postorder(TreeNode* root) {
    if (!root) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> preorder = {1,2,4,7,3,5,6,8};
    vector<int> inorder = {4,7,2,1,5,3,8,6};
    auto root = reConstructBinaryTree(preorder, inorder);
    // 输出后序遍历结果检查一下是否正确
    print_postorder(root);

    return 0;
}
