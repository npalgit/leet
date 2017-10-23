// Problem 114

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

    void makeFlat(TreeNode * head, Stack & myStack) {
        
        
        
        /*
        1. Simple DFS Solution.
        2. if right subtree exists, put in stack & disconnect
        3. if left subtree exists, make left subtree as right subtree, and make left as NULL
        4. Follow the Algo.
        
        
        
        
        
        
        
        */
        if(head == NULL) return;
        
        if(head->right) {
            myStack.push(head->right);
            head->right = NULL; // IMP STEP of Disonnection
            
        }
        if(head->left) {
            head->right = head->left;
            head->left = NULL;// IMP STEP of Disconnection
        }
        
        if(head->left == NULL && head->right == NULL){ // If LEaf Node
            
            if(myStack.empty() != 1) {
                
                TreeNode * top = myStack.top();
                head->right = top;
                myStack.pop();
        
            }
        
            else return;
        }
        
        makeFlat(head->right, myStack);
        
        
    }
    void flatten(TreeNode* root) {
        
        Stack myStack;
        makeFlat(root, myStack);
        
    }
};