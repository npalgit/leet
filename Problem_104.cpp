// Problem 104

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

typedef pair<int, int> Pair;

class Solution {
public:
    
    Pair checkBalance(TreeNode * head) {
        
        if(head == NULL) return make_pair(1, 0);
        
        if(head->left == NULL && head->right == NULL) return make_pair(1, 1);
        
        Pair left = checkBalance(head->left);
        Pair right = checkBalance(head->right);
        
        int hDiff = abs(left.second - right.second);
        
        int currValid = hDiff <= 1;
        
        int valid = left.first * right.first * currValid;
        
        int hMax = max(left.second, right.second) + 1;
        
        return make_pair(valid, hMax);
        
        
    }
    
    int maxDepth(TreeNode* root) {
        
        Pair result = checkBalance(root);
        
        return result.second;
        
    }
};