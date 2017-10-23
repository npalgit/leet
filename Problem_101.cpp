// Problem 101

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

typedef pair<TreeNode*, TreeNode*> Pair;
typedef queue<Pair> Queue;

class Solution {
public:

    bool helpSymmetric(TreeNode *left, TreeNode* right){
        
        
        if(left == NULL && right == NULL) return true;
        if(left == NULL || right == NULL) return false;
        
        if(left->val != right->val) return false;
        
        bool outwardSym = helpSymmetric(left->left, right->right);
        bool inwardSym = helpSymmetric(left->right, right->left);
        
        return inwardSym * outwardSym;
        
        
    }
    bool isSymmetric(TreeNode* root) {
        
        
        if(root == NULL) return true;
        
        // Recursive Solution
        //return helpSymmetric(root->left, root->right);
        
        
        // Iterative Solution
        Queue myQ;
        
        myQ.push(make_pair(root->left, root->right));
        
        bool answer = true;
        
        while(myQ.size()){
            
            
            Pair out = myQ.front();
            
            TreeNode * left = out.first;
            TreeNode * right = out.second;
            
            myQ.pop();
            
            if(left == NULL && right == NULL) continue;
            
            if(left == NULL || right == NULL) return false;
        
            if(left->val != right->val) return false;
            
            
            
            myQ.push(make_pair(left->left, right->right));
            myQ.push(make_pair(left->right, right->left));

        }
        
        return answer;
        
        
    }
};