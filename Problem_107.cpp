// Problem 107

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
typedef queue<TreeNode *> Queue;
typedef vector<Vector> Matrix;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        
        Queue back;
        Queue front;
        
        Matrix table;
        
        Vector myVect;
        
        back.push(root);
        
        TreeNode * top;
        if(root == NULL) return table;
        
            
        do{
            //cout << "Inside Cycle" << endl;
            
            myVect.clear();
            while(back.empty() != 1){
                
            
                top = back.front();
                
                if(top->left) front.push(top->left);
                if(top->right) front.push(top->right);
                
                myVect.push_back(top->val);
                
                back.pop();
                
            }
            if(myVect.size())table.insert(table.begin(), myVect);
            
            
            myVect.clear();
            while(front.empty() != 1){
                
            
                top = front.front();
                
                if(top->left) back.push(top->left);
                if(top->right) back.push(top->right);
                
                myVect.push_back(top->val);
                
                front.pop();
                
            }
            if(myVect.size())table.insert(table.begin(), myVect);
            
            
            
        }while(back.empty() != 1 || front.empty() != 1);
        
        //printTable(table);
        
        return table;
        
        
    }
};