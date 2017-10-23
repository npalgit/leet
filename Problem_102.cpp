// Problem 102

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

typedef queue<TreeNode *> Queue;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        /*
        1. Using 2 Queues
        
        
        */
        
        Matrix table;
        Vector row;
        
        Queue myQ1;
        Queue myQ2;
        
        if(root == NULL) return table;
        
        myQ1.push(root);
        
        while(myQ1.size() || myQ2.size()){
            
            row.clear();
            while(myQ1.size()){
                
                TreeNode * topNode = myQ1.front();
                if(topNode->left) myQ2.push(topNode->left);
                if(topNode->right) myQ2.push(topNode->right);
                
                row.push_back(topNode->val);
                myQ1.pop();
                
            }
            
            if(row.size())table.push_back(row);
            
            row.clear();
            while(myQ2.size()){
                
                TreeNode * topNode = myQ2.front();
                if(topNode->left) myQ1.push(topNode->left);
                if(topNode->right) myQ1.push(topNode->right);
                
                row.push_back(topNode->val);
                myQ2.pop();
                
            }
            if(row.size())table.push_back(row);
            
        }
        
        
        return table;
        
        
    }
};