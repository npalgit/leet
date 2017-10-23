// Problem 236

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

struct Node{

    int found = 0;
    TreeNode * lca = NULL;
    
};

class Solution {
public:
    
    Node * findLCA(TreeNode * head, TreeNode * p, TreeNode* q){
        
        /*
        
        1. This question is all about covering all the cases.
        2. Think as much as you can.
        3. Also, it is very important to know the order in which these checks and cases are executed.
        4. Cases:
            a. NULL head
            b. LEAF node
            c. If LCA is found, just push the result upwards, without any further check.
            d. If one node is found downwards, and other node is the head itself
            e. if Node matches the head, update the found value.
            f. If left and right subtree have founds with different values, head is lca
            g. if nothing above works, just propagate the found upwards.
            
        5. All cases have been well documented in the code.
        
        */
        
        Node * myNode = new Node;
        // Case a.
        if(head == NULL) return myNode;
        
        // Case b.
        if(head->left == NULL && head->right == NULL){
            
            if(head == p) myNode->found = 1;
            if(head == q) myNode->found = 2;
            
            return myNode;
        }
        
        Node* leftNode = findLCA(head->left, p, q);
        Node* rightNode = findLCA(head->right, p, q);
        
        
        // Case c.
        if(leftNode->lca != NULL) return leftNode;
        if(rightNode->lca != NULL) return rightNode;
    
        // Case d. 
        if(head == p && leftNode->found == 2) myNode->lca = head;
        if(head == p && rightNode->found == 2) myNode->lca = head;
        
        if(head == q && leftNode->found == 1) myNode->lca = head;
        if(head == q && rightNode->found == 1) myNode->lca = head;
        
        
        // Case e.
        if(head == p) myNode->found = 1;
        if(head == q) myNode->found = 2;
        
        
        
        // Case f.
        if(leftNode->found == 1 && rightNode->found == 2) myNode->lca = head;
        if(leftNode->found == 2 && rightNode->found == 1) myNode->lca = head;
        
        
        
        // Case g.
        if(leftNode->found == 1) myNode->found = 1;
        if(leftNode->found == 2) myNode->found = 2;
        
        
        if(rightNode->found == 1) myNode->found = 1;
        if(rightNode->found == 2) myNode->found = 2;
        
        return myNode;
    
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        Node * head = findLCA(root, p, q);
        
        return head->lca;
        
    }
};