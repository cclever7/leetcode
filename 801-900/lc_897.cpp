/**
 * 递增顺序搜索树
 * 
 * 给你一棵二叉搜索树，请你 按中序遍历 将其重新排列为一棵递增顺序搜索树，
 * 使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，
 * 只有一个右子节点。
 * 
 * 示例 1：
 * 输入：root = [5,1,7]
 * 输出：[1,null,5,null,7]
 * 
 * 解法：中序递归遍历
 */
#include <iostream>
#include <vector>
#include "../common.h"
using namespace std;

class Solution {
public:
    vector<TreeNode *> vec;
    TreeNode* increasingBST(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        traverse(root);
        for(TreeNode *item : vec) {
            item->left = nullptr;
            item->right = nullptr;
        }
        for(int i = 0; i < vec.size() - 1; i++) {
            int j = i + 1;
            vec[i]->right = vec[j];
        }
        return vec[0];
    }

    void traverse(TreeNode *root) {
        if(root == nullptr)
            return ;
        if(root->left != nullptr)
            traverse(root->left);
        vec.push_back(root);
        if(root->right != nullptr)
            traverse(root->right);
    }
};

int main() {
    Solution s;
    TreeNode t1(5);
    TreeNode t2(1);
    TreeNode t3(7);
    t1.left = &t2;
    t1.right = &t3;
    s.traverse(&t1);
    for(const TreeNode *t : s.vec) {
        cout << t->val << endl;
    }
    return 0;
}