// Problem 230

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

class Solution {
public:

    int giveSmallest(TreeNode * head, int * ptr, int ans,  int k){
       
       
            /*
            
            1. Keep a global pointer that keeps on updating value.
            2. Whenever that global pointer value equals k, put answer in another passing integer.
            3. Inorder Traversal of a BST gives elements in Sorted Order.
            4. Whenever, that passing integer is not equal to INT_MIN, keep updating the value;
            
            
            */
            if(ans != INT_MIN) return ans; 
            if(head == NULL) return ans;
            
            
            int left = giveSmallest(head->left, ptr, ans, k);
            if(left != INT_MIN) ans = left;
            
            *ptr = *ptr +1;
            cout << "Value of Ptr = " << *ptr << endl;
            if(*ptr == k) {
                
                ans = head->val;
                cout << "Answer Updated = " << ans << endl;
                
                return ans;
            } 
            
            int right = giveSmallest(head->right, ptr, ans, k);
            if(right != INT_MIN) ans = right;
            
            return ans;
            
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        int small = 0;
        int ans = INT_MIN;
        int *ptr = &small;
        
        ans = giveSmallest(root, ptr, ans, k);
        
        return ans;
        
        
    }
};