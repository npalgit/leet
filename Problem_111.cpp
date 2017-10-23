// Problem 111

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
using namespace std;


class Solution {
public:
    int minDepth(TreeNode* root) {
        
        /*
        1. Learn only one corner case over here.
        
        */
        if(root == NULL) return 0;
        
        if(root->left == NULL && root->right == NULL) return 1;
        
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        
        // Remember the Corner Case over here.
        if(left && right )return min(left+1, right+1);
        else return max(left+1, right+1);
        
    }
};