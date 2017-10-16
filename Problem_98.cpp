// Problem 98

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
 
 typedef pair<long int, long int> IntPair;
 typedef pair<int, IntPair> Pair;
 
 
class Solution {

private:
    TreeNode * prev = NULL;
public:

    
    int validate(TreeNode * root, int &check){
        
        if(prev != NULL) {
            check = check * (prev->val < root->val);
            //cout << "Prev = " <<prev->val << "  Root = " << root->val;
        }
        //cout << "Prev = " <<prev << "  Root = " << root << endl;
        prev = root;
        
        
        return check;
        
    }
    
    int checkBST(TreeNode * root, int &check){
        
        if(root == NULL) return 1;
        
        check = check * checkBST(root->left, check);
        
        check = check * validate(root, check);
        //cout << root->val << "--";
    
        check = check * checkBST(root->right, check);
        
        return check;
        
        
    }
    
    Pair helpValid(TreeNode * head) {
        
        if(head == NULL) {
            
            return {1, {LONG_MAX, LONG_MIN}};
            
        }
        
        if(head->left == NULL && head->right == NULL) {
            
            return {1, {head->val, head->val}};
            
        }
        
        
        Pair left = helpValid(head->left);
        Pair right = helpValid(head->right);
        
        
        long int headVal = head->val;
        
        int currValid = (head->val > left.second.second) && (head->val < right.second.first);
        
        int valid = currValid * left.first * right.first;
        
        int minE = min(left.second.first, min(headVal, right.second.first));
        int maxE = max(right.second.second, max(headVal, right.second.second));
        
        
        return {valid, {minE, maxE}};
        
    }
    bool isValidBST(TreeNode* root) {
        
        /*
        int check = 1;
        
        return checkBST(root, check);
        */
        
        if(root == NULL) return true;
        
        Pair answer = helpValid(root);
        
        return answer.first;
        
        
        
        
    }
};