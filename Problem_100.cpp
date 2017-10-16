// Problem 100

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
    void  inOrder(TreeNode * head, string & inorder ) {
        
        if(head == NULL) {
            
            inorder = inorder + ",null"; 
            return;
            
        }
        
        inOrder(head->left, inorder);
        
        inorder = inorder + to_string(head->val);
        
        inOrder(head->right, inorder);
        
        
        
    }
    
    void  postOrder(TreeNode * head, string & postorder ) {
        
        if(head == NULL) {
            
            postorder = postorder + ",null"; 
            return;
            
        }
        
        postOrder(head->left, postorder);
        postOrder(head->right, postorder);
        
        postorder = postorder +  "," + to_string(head->val);
        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        string inP = "", inQ = "",poP = "", poQ = "";
        
        inOrder(p, inP);
        inOrder(q, inQ);
        
        postOrder(p, poP);
        postOrder(q, poQ);
        
        if(poP == poQ && inP == inQ) return true;
        
        return false;
        
    }
};