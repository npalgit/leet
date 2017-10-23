// Problem 129

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


    int giveSum(TreeNode * head, int beforeSum){
    
         if(head == NULL) return 0;
        
        if(head->left == NULL && head->right == NULL) {
            
            return (beforeSum*10 + head->val);
            
            
        } 
        
        int left = giveSum(head->left, (beforeSum *10 + head->val));
        int right = giveSum(head->right, (beforeSum *10 + head->val));
        
        return (left + right);
        
        
        
        
            
        
    }
    
    int sumNumbers(TreeNode* root) {
        
        int ans = giveSum(root, 0);
        
        return ans;
       
        
    }
};