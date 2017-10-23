// Problem 250

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
    
    Pair helpCount(TreeNode * head){
        
        /*
        1. This is an easy problem
        2. The only trick is to visualize all the cases.
        3. See how pair can be used to return in Tree Problems.
        
        */
        
        if(head == NULL) return make_pair(0,1);
        
        if(head->left == NULL && head->right == NULL) return make_pair(1, 1);
        
        Pair left = helpCount(head->left);
        Pair right = helpCount(head->right);
        
        if(head->left && head->right == NULL) {
            
            if(head->left->val == head->val && left.second) return make_pair(left.first + 1, 1);
            else return make_pair(left.first, 0);
            
        }
        
        
        if(head->right && head->left == NULL) {
            
            if(head->right->val == head->val  && right.second) return make_pair(right.first + 1, 1);
            else return make_pair(right.first, 0);
            
        }
        
        
        if(head->left && head->right) {
            
            if(head->left->val == head->val && head->right->val == head->val) return make_pair(left.first + right.first + 1, 1);
            else return make_pair(left.first + right.first, 0);
            
        }
        
       //cout << "I should never reach here" << endl; 
       return make_pair(0,0);
         
    }
    int countUnivalSubtrees(TreeNode* root) {
        
        Pair ans = helpCount(root);
        
        return ans.first;
    }
};