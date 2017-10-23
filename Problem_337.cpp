// Problem 337


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
 
struct Ans {
    
    int notUse;
    int Use;
    
    // Constructor
    Ans()
    :notUse(0), Use(0)
    {}
    
};

class Solution {
public:

    
    Ans* robHelp(TreeNode * head){
        
        //Ans answer;
        Ans *ansPtr = new Ans();
        
        if(head == NULL) return ansPtr;
        
        Ans *left = robHelp(head->left);
        Ans *right  = robHelp(head->right);
        
        ansPtr->Use = left->notUse + right->notUse + head->val;
        
        //ansPtr->notUse = max(left->Use + right->notUse, max(right->Use + left->notUse, max(left->Use + right->Use, left->notUse + right->notUse)));
        
        ansPtr->notUse = max(left->Use, left->notUse) + max(right->Use, right->notUse);
        
        return ansPtr;
        
        
    }
    
    int rob(TreeNode* root) {
        
        /*
        1. Very simple problem
        2. The idea is to get to the Maths and Logic of the Problem
        
        */
        
        Ans *ansPtr = robHelp(root);
        
        //cout << "Not Use = " << ansPtr->notUse << endl;
        //cout << "Use = " << ansPtr->Use << endl;
        
        return max(ansPtr->notUse, ansPtr->Use);
        
        
        
        
        
        
    }
};