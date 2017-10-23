// Problem 272


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
typedef pair<double, int> Pair;
typedef vector<int> Vector;
typedef stack<int> Stack;
typedef priority_queue<Pair, vector<Pair>, less<Pair>> PQ;


class Solution {
public:

    void travelTree(TreeNode * head, PQ & myPQ, double target, int k){
        
        if(head == NULL) return;
        
        double distance = fabs(double(head->val) - target);
        //cout << "Distance = " << distance << ", Root Val = " << head->val << endl;
        myPQ.push(make_pair(distance, head->val));
        
        if(myPQ.size() > k) myPQ.pop();
        
        travelTree(head->left, myPQ, target, k);
        travelTree(head->right, myPQ, target, k);
        
        
    }
    
    
    
    void inOrder(TreeNode * head, Vector & answer, int k, double target, int index) {
        
        if(head == NULL) return;
        
        inOrder(head->left, answer, k, target, index);
        
        
        //cout << "Distance = " << distance << ", Root Val = " << head->val << endl;
        
        if(answer.size() < k) answer.push_back(head->val);
        else {
            
            double distance = fabs(double(head->val) - target);
            double distIndexVect = fabs(double(answer[index]) - target);
            
            if(distance < distIndexVect){
                
                answer[index] = head->val;
                index++;
                if(index == k) index = 0;
                
            }
            
            else return;
            
            
        }
        
        inOrder(head->right, answer, k, target, index);
        
        
        
        
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        /*
        Vector answer;
        
        PQ myPQ;
        
        travelTree(root, myPQ, target, k);
        
        while(myPQ.size()){
            
            
            answer.push_back(myPQ.top().second);
            myPQ.pop();
            
        }
        
        
        return answer;
        
        */
        
        
        Vector answer;
        
        inOrder(root, answer, k, target, 0);
        
        return answer;
        
        
        
        
    }
};