// Problem 145

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

typedef vector<int> Vector;
typedef stack<TreeNode *> Stack;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        Stack myStack;
        Vector answer;
        
        TreeNode * currentNode = root;
        TreeNode * lastNode = NULL;
        
        while(currentNode || myStack.size()){
            
            
            if(currentNode){
                
                myStack.push(currentNode);
                currentNode = currentNode->left;
                
            }
            
            else{
                
                TreeNode * topNode = myStack.top();
                
                // Right Subtree Exists and has not been visited before
                if(topNode->right && lastNode != topNode->right){
                    
                    currentNode = topNode->right;
                    
                }
                
                // Either Right Subtree doesn't exist or it hasn't been visited before
                else{
                    
                    answer.push_back(topNode->val);
                    lastNode = topNode;
                    myStack.pop();
                    
                }
                
                
                
            }
            
        }
        
        return answer;
        
    }
};