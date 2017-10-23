// Problem 222

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        
        /*
        
        1. If Left Height == Right Height, then return (2^level) -1.
        2. If Left Height != Right Height, move left and right, until left height and right are not equal,
           and then add 1 for the current node, and then further move left and right.
        
        */
        
        int lHt = 0;
        int rHt = 0;
        
        TreeNode * lNode = root, *rNode = root;
        
        while(lNode != NULL) {
         
            lNode = lNode->left;
            lHt++;
        }
        
        while(rNode != NULL){
            
            rNode = rNode->right;
            rHt++;
        }
        
        if(lHt == rHt) return pow(2, lHt)-1;
        
        else return 1 + countNodes(root->left) + countNodes(root->right);
        
        
    }
};