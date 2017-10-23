// Problem 117

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
 
 using namespace std;
 
 typedef queue<TreeLinkNode *> Queue;
 
 
class Solution {

private:
    Queue myQ1;
    Queue myQ2;
    
public:
    void connect(TreeLinkNode *root) {
        
        if(root == NULL) return;
        myQ1.push(root);
        while(myQ1.size() || myQ2.size()) {
            
            while(myQ1.size()) {
                
                TreeLinkNode * top = myQ1.front();
                //cout << "Left = " << top->left << ""
                if(top->left != NULL) myQ2.push(top->left);
                if(top->right != NULL) myQ2.push(top->right);
                
                myQ1.pop();
                if(myQ1.empty()) top->next = NULL;
                else top->next = myQ1.front();
                
                
            }
            
            while(myQ2.size()) {
                
                TreeLinkNode * top = myQ2.front();
                if(top->left != NULL) myQ1.push(top->left);
                if(top->right != NULL) myQ1.push(top->right);
                
                myQ2.pop();
                if(myQ2.empty()) top->next = NULL;
                else top->next = myQ2.front();
                
                
                
                
            }
            
            
            
        }
        
        
        
    }
};