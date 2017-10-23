// Problem 298

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

    int helpFindLong(TreeNode * head, int count, int value){
        
        
        if(head == NULL) return count;
        
        
        if(value == head->val - 1) count++;
        else count  = 1;
        
        
        
        int left = helpFindLong(head->left, count, head->val);
        int right = helpFindLong(head->right, count, head->val);
        
        
        return max(count, max(left, right));
        
        
        
    }
    
    int longestConsecutive(TreeNode* root) {
        
        /*
        1. This seems a bit tricky problem. Observe how the function of DFS has been written here.
        
        */
        
        if(root == NULL) return 0;
        int answer = helpFindLong(root, 1, root->val);            
        
        return answer;
        
    }
};