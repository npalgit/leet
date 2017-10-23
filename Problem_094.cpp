// Problem 94

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
    vector<int> inorderTraversal(TreeNode* root) {
 
        /*
        Recursive Solution
        
        Vector myVect;
        if(root == NULL) return myVect;
        
        Vector leftVect = inorderTraversal(root->left);
        
        myVect.insert(myVect.end(), leftVect.begin(), leftVect.end());
        
        myVect.push_back(root->val);
        
        Vector rightVect = inorderTraversal(root->right);
        
        myVect.insert(myVect.end(), rightVect.begin(), rightVect.end());
        
        return myVect;
        
        
        */
        
        
        
        /*
        
        Traversal with Stack. O(n) in time and space.
        
        1) Create an empty stack S.
        2) Initialize current node as root
        3) Push the current node to S and set current = current->left until current is NULL
        4) If current is NULL and stack is not empty then 
            a) Pop the top item from stack.
            b) Print the popped item, set current = popped_item->right 
            c) Go to step 3.
        5) If current is NULL and stack is empty then we are done.
        
        
        
        
        
        Stack myStack;
        Vector myVect;
        TreeNode * current = root;
        //myStack.push(root);
        
        while(current != NULL || myStack.empty() != 1){
            
            
            if(current != NULL){
                myStack.push(current);
                current = current->left;
               // cout << "Current  =  " << current << endl;
            }
            
            
            
            if(current == NULL && myStack.empty() != 1){
                
                TreeNode * topNode = myStack.top();
                myVect.push_back(topNode->val);
                cout << "Pushed Back = " << topNode->val << endl; 
                current = topNode->right;
                
                myStack.pop();
                
                
            }
            
            
        }
        
        return myVect;
        
        */
        
        
        
        
        
        
        /*
        
        Morris Traversal : In Order Traversal without Stack 
        
        1. Initialize current as root 
        2. While current is not NULL
            If current does not have left child
                a) Print current’s data
                b) Go to the right, i.e., current = current->right
             Else
                a) Move to Left Subtree.
                b) Reach to the predecessor - whose right is not NULL and which is not current
                c) If predecessor has a right, that means, we made the link before, so this time remove the link, after moving right.
                d) If predecessor doesn;t have a right, make it's right connection to the current, and move to left of current.
               
        
        
        */
        
        
        Vector myVect;
        TreeNode * current = root;
        TreeNode * predes;
        
        while(current != NULL){
            
            
            if(current->left == NULL){
                
                myVect.push_back(current->val);
                current = current->right;
                
                
            }
            
            
            else{
                
                predes = current->left;
                while(predes->right != NULL && predes->right != current){
                    
                    predes = predes->right;
                }
                
                if(predes->right){
                    predes->right = NULL;
                    myVect.push_back(current->val);
                    current = current->right;
                    
                } 
                
                else{
                
                    predes->right = current;
                    current = current->left;
                }
            }
            
        }
        
        return myVect;
        
    }
};