// Problem 199

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
typedef queue<TreeNode*> Queue;


class Solution {
public:

   
    vector<int> rightSideView(TreeNode* root) {
        
        
        /*
        1. Simple BFS
        2. Afterwards, take the backmost element in the Queue
        3. Each of the backmost element in the Queue will be viewable from the right side of the tree.
        
        */
                
        Queue back;
        Queue front;
        
        
        
        Vector myVect;
        
        back.push(root);
        
        TreeNode * top;
        TreeNode * last = NULL;
        
        if(root == NULL) return myVect;
        
            
        do{
            
            //cout << "Inside Cycle" << endl;
            
            last = NULL;
            while(back.empty() != 1){
                
                if(last == NULL) last = back.back();
                //cout << "Right Element = " << last->val << endl;
                top = back.front();
                
                if(top->left) front.push(top->left);
                if(top->right) front.push(top->right);
                
                
                
                back.pop();
                
            }
            if(last)myVect.push_back(last->val);
            
            
            
            //cout << "After first" << endl;
            
            last = NULL;
            while(front.empty() != 1){
                
                if(last == NULL) last = front.back();
               // cout << "Right Element = " << last->val << endl;
                
                top = front.front();
                
                if(top->left) back.push(top->left);
                if(top->right) back.push(top->right);
                
                
                
                front.pop();
                
            }
            if(last)myVect.push_back(last->val);
            
            
            
        }while(back.empty() != 1 || front.empty() != 1);
        
      
        return myVect;
        
        
    }
};