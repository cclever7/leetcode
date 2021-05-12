/**
 * 二叉搜索树的范围和
 * 
 * 给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。
 * 
 * 示例 1：
 * 输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
 * 输出：32
 * 
 */

#include <iostream>
#include "../common.h"
using namespace std;

class Solution {
public:
    int res;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        traverse(root, low, high);
        return res;
    }

    void traverse(TreeNode *root, int low, int high) {
        if(!root)
            return ;
        if(root->left) {
            traverse(root->left, low, high);
        }
        int val = root->val;
        if(val >= low && val <= high) {
            res += val;
        }
        if(root->right) {
            traverse(root->right, low, high);
        }
    }

};

int main() {

}