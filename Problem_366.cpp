// Problem 366


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
typedef vector<Vector> Matrix;

class Solution {
public:

    
    int enterLeaves(TreeNode * head, Vector & partial, Matrix & result){
        
        /*
        
        1. Simple Question
        2. Corner Cases Handling thinking is important. It is aldso easy.
        3. Self Explanatory Question
        
        
        */
         
         
        if(head == NULL) return 0;
        
        //cout << "Value = " << head->val << endl;
        
        if(head->left == NULL && head->right == NULL) {
            
            partial.push_back(head->val);
            return 1;
            
        }
        
        
        
        int left = enterLeaves(head->left, partial, result);
        int right = enterLeaves(head->right, partial, result);
        
        if(left == 1) head->left = NULL;
        if(right == 1) head->right = NULL;
        
        return 0;
        
        
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
    
        Matrix result;
        Vector partial;
        if(root == NULL) return result;
        
        while(root->left != NULL || root->right != NULL){
            
            partial.clear();
            //cout << "Enter Again" << endl;
            
            enterLeaves(root, partial, result);
            result.push_back(partial);
            
        }
        
        partial.clear();
        partial.push_back(root->val);
        result.push_back(partial);
        
        
        return result;
        
        
        
    }
};