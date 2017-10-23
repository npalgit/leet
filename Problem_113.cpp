// Problem 113

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
    
    void checkSum(TreeNode * head, Matrix &table, Vector path, int desiredSum, int beforeSum){
        
        
        if(head == NULL) return;
        
        if(head->left == NULL && head->right == NULL) {
            
            path.push_back(head->val);
            if(head->val + beforeSum == desiredSum) table.push_back(path);
            
            //return path;
        }
        
        path.push_back(head->val);
        
        int afterSum = beforeSum + head->val;
        
        checkSum(head->left, table, path, desiredSum, afterSum);
        
        checkSum(head->right, table, path, desiredSum, afterSum);
        
        //return path;
        
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {


        /*
        
        1. Very simple Solution.
        2. at every step, I check the sum, and return if condition is met.
        
        */
        Matrix table;
        Vector path;
        
        checkSum(root, table, path, sum, 0);
        
        return table;
        
        
        
    }
};