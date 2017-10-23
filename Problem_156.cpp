// Problem 156

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

typedef stack<TreeNode *> Stack;
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        
        /*
        1. This is in turn a very easy question
        2. Key thing to notice is that corner cases can be avoided if we keep things simple.
        3. Corner Cases:
            a. When there is no right sibling
            b. When there is no Parent
        
        
        */
        
        
        Stack myStack;
        TreeNode * head = root;
        if(root == NULL) return NULL;
        
        while(head != NULL){
            
            myStack.push(head);
            head = head->left;
        }
        
        TreeNode * newRoot = myStack.top();
        TreeNode * oldParent;
        
        while(myStack.size() != 0){
            
            head = myStack.top();
            myStack.pop();
            if(myStack.size() != 0)oldParent = myStack.top();
            else break;
            
            if(oldParent->right != NULL){
                
                head->left = oldParent->right;
                
            }
            
            if(oldParent){
                
                
                head->right = oldParent;
            }
            
            oldParent->left = NULL;
            oldParent->right = NULL;
            
        }    
    
        
        return newRoot;
    }
};