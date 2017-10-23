// Problem 144

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
 typedef stack<TreeNode*> Stack;
 typedef Vector::iterator VectorItr;
 
class Solution {
public:



    vector<int> preorderTraversal(TreeNode* root) {
        
        /*
        
        1. There are mainly 2 types of Tree Algos:
            a. One where we are doing complex analysis. Here we need :
                i.   Null Case
                ii.  Leaf Node Case
                iii. Left
                iv.  Right
                
                Further Processing
                
            b. Others are traversal algos, where we don't need the Leaf Node Condition.
        
                i.   Null Case
                ii. Left
                iii.  Right
                
                Further Processing
        
        

        
        Vector myVect;
        
        if(root == NULL) return myVect;
        
        myVect.push_back(root->val);
        
        Vector leftVect = preorderTraversal(root->left);
        Vector rightVect = preorderTraversal(root->right);
        
        myVect.insert(myVect.end(), leftVect.begin(), leftVect.end());
        myVect.insert(myVect.end(), rightVect.begin(), rightVect.end());
        
        return myVect;
        
        */
        
        
        
        
        /*
        
        Traversal with Stack. O(n) in time and space.
        
        1) Create an empty stack S.
        2) Initialize current node as root
        3) If right child exists, push right child to stack
        4) Visit Current, current = current->left
        5) If current is NULL and stack is not empty then 
            a) Pop the top item from stack.
            b) set current = popped_item
            c) Go to step 3.
        5) If current is NULL and stack is empty then we are done.
        
        
        
        
        
        Stack myStack;
        Vector myVect;
        TreeNode * current = root;
        //myStack.push(root);
        
        while(current != NULL || myStack.empty() != 1){
            
            
             if(current && current->right != NULL){
                myStack.push(current->right);
                //current = current->left;
               // cout << "Current  =  " << current << endl;
            }
            
            if(current){
                myVect.push_back(current->val);
                current = current ->left;
            }
            
            if(current == NULL && myStack.empty() != 1){
                
                TreeNode * topNode = myStack.top();
               // myVect.push_back(topNode->val);
                //cout << "Pushed Back = " << topNode->val << endl; 
                current = topNode;
                
                myStack.pop();
                
                
            }
            
            
            
            
        }
        
        return myVect;
        
        */
        
        
        
        /*
        
               Morris Traversal : Pre Order Traversal without Stack 
        
        1. Initialize current as root 
        2. While current is not NULL
        
            If current does not have left child
                a) Print current’s data
                b) Go to the right, i.e., current = current->right
             Else
                a) Move to Left Subtree.
                b) Reach to the predecessor - whose right is not NULL and which is not current
                c) If predecessor has a right, that means, we made the link before, so this time remove the link, after moving right.
                d) If predecessor doesn;t have a right, make it's right connection to the current, ...PRINT...,and move to left of current.
               
               NOTE: The algorithm for Morris Traversal for Inorder and PreOrder is the same, except that there is an
               extra visiting condition in the PreOrder case after making predecesssor's right connection.
               
               
               OTHER WORDS:
               
               1. If left child is NULL, Visit the current. Move Right.
               2. If Left child is not NULL,
                    a. Check if moving right comes back to current. In this case, remove predecessor's right.
                    b. If you reach a node while moving right whose right is null, this is the predecessor. 
                        Make its right point to current. Print Current,  and move left.
        
        
        
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
                    //myVect.push_back(current->val);
                    current = current->right;
                    
                } 
                
                else{
                
                    predes->right = current;
                    myVect.push_back(current->val);
                    current = current->left;
                }
            }
            
        }
        
        return myVect;
        
        
    }
};