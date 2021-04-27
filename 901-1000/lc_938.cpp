/**
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