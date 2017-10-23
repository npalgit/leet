// Problem 103
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

typedef deque<TreeNode *> Queue;

class Solution {
public:

       void printTable(Matrix & table){
        
        for(int i = 0; i < table.size(); i++){
            
            
            for(int j = 0; j < table[i].size(); j++){
                
                cout << table[i][j] << " : ";
            }
            
            cout << endl;
        }
        
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        
        /*
        
        1. A solution using 2 Queues
        2. The idea is simple to just use different push_front and push_back strategies while creating the vector.
        3. Other than that, it is simply a BFS.
        
        
        
        */
        Queue back;
        Queue front;
        
        Matrix table;
        
        Vector myVect;
        
        back.push_back(root);
        
        TreeNode * top;
        if(root == NULL) return table;
        
            
        do{
            //cout << "Inside Cycle" << endl;
            
            myVect.clear();
            while(back.empty() != 1){
                
            
                top = back.front();
                
                if(top->left) front.push_back(top->left);
                if(top->right) front.push_back(top->right);
                
                myVect.push_back(top->val);
                
                back.pop_front();
                
            }
            if(myVect.size())table.push_back(myVect);
            
            
            myVect.clear();
            while(front.empty() != 1){
                
            
                top = front.back();
                
                if(top->right) back.push_front(top->right);
                if(top->left) back.push_front(top->left);
                
                
                myVect.push_back(top->val);
                
                front.pop_back();
                
            }
            if(myVect.size())table.push_back(myVect);
            
            
            
        }while(back.empty() != 1 || front.empty() != 1);
        
        //printTable(table);
        
        return table;
        
        
        
    }
};