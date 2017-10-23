// Problem 106

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
 typedef map<int,int> HashMap;
 
 
class Solution {
    
private:

    HashMap myMap;
    
public:
 
    TreeNode * createTree(Vector & inOrder, Vector & postOrder, int postStart, int postEnd, int inStart, int inEnd){
        
        
        /*
        
        1. Very simple Question
        2. Null Condition arises when inStart > inEnd
        3. find Index of Root in Inorder
        4. Write Traversals and index them in random order, and then write left and right functions.
        
        
        */
        if(inStart > inEnd) return NULL;
        
        int newRootPosn = 0;
        
        
        /*
        for(int i = 0; i < inOrder.size(); i++){
            
            if(postOrder[postEnd] == inOrder[i]){
                
                newRootPosn = i;
                break;
            }
            
        }
        
        
        */
        int root = postOrder[postEnd];
        
        newRootPosn = myMap[root];
        
        TreeNode * head = new TreeNode(postOrder[postEnd]);
        
        head->left = createTree(inOrder, postOrder, postStart, newRootPosn - 1 + postStart - inStart, inStart, newRootPosn -1);
        
        head->right = createTree(inOrder, postOrder, newRootPosn + postStart - inStart, postEnd-1, newRootPosn +1, inEnd);
        
        return head;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        
        
        
        int i = 0;
        for(auto x: inorder) myMap[x] = i++;
        
        TreeNode * head = createTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
        
        return head;
        
    }
};