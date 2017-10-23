// Problem 270


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
    int closestValue(TreeNode* root, double target) {
        
        /*
        int result = root->val;
        
        TreeNode * child;
        if(target > root->val) child = root->right;
        else child = root->left;
        
        if(child == NULL) return result;
        else result = closestValue(child, target);
        
        
        if(abs(target - result) > abs(target - root->val)) return root->val;
        
        return result;
            
          
         */
         
         
         int result = root->val;
         
         TreeNode * child = root;
         
         while(child){
             
             // If Child is Closer to Target, update result with Child Value
             // At every point, we compare the closeness of our target with the result, and the node
             if(abs(child->val - target) < abs(result - target)) result = child->val;
             
             if(target > child->val) child = child->right;
             else child = child->left;
             
         }
         
         return result;
            
        
        
        
        
            
        
        
    }
};