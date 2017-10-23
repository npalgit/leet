// Problem 105
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
 typedef Vector::iterator VectorItr;
 typedef map<int, int> HashMap;
 
class Solution {
    
private:
    HashMap myMap;
    
public:

    void printVector(Vector myVect){
        
        for(auto x: myVect) cout << x;
        cout << endl;
        
    }
    
    TreeNode * helpCreate(Vector & preorder, Vector & inorder, int preStart, int inStart, int inEnd){
        
        
        if(inStart > inEnd) return NULL;
        
        TreeNode * head = new TreeNode(preorder[preStart]);
        
        int newRootPosn = 0;
    
        /*    
        for(int i = 0; i < inorder.size(); i++){
            
            if(inorder[i] == preorder[preStart]) {
                newRootPosn = i;
                break;
            }
            
        }
        
        */
        
        int root = preorder[preStart];
        newRootPosn = myMap[root];
        
        head->left = helpCreate(preorder, inorder, preStart+1, inStart, newRootPosn-1);
        head->right = helpCreate(preorder, inorder, preStart+1+(newRootPosn-inStart), newRootPosn+1, inEnd);
        
        return head;
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        /*
        
        1. Very simple Question
        2. Null Condition arises when inStart > inEnd
        3. find Index of Root in Inorder
        4. Write Traversals and index them in random order, and then write left and right functions.
        
        
        */
        
        
        int i = 0;
        
        for(auto x : inorder) myMap[x] = i++;
        
        TreeNode *head = helpCreate(preorder, inorder, 0, 0, inorder.size()-1  );
        
 
        return head;
 
 
        
    }
};