// Problem 108

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

class Solution {
public:

    void printVector(Vector & myVect){
        
        for(auto x: myVect) cout << x << " : ";
        cout << endl;
        
    }
    
    TreeNode * makeTree(Vector & myVect){
        
        //printVector(myVect);
        cout << endl<< endl;
        
        if(myVect.size() == NULL) return NULL;
        
        int vectSize = myVect.size();
        int left = 0;
        int right = vectSize - 1;
        
        int mid  = vectSize/2;
        
        TreeNode *head = new TreeNode(myVect[mid]);
        
        VectorItr itr1 = myVect.begin();
        VectorItr itr2 = myVect.begin();
        
        //cout << "Mid = " << mid << "  Left = " << left << "  Right = " << right << endl;
        
        if(mid-1 >= left){
            
            advance(itr2, mid);
            
            Vector leftVect(itr1, itr2);
            
            head->left = makeTree(leftVect);
        }
        
        if(mid+1 <= right){
            
            itr1 = myVect.begin();
            itr2 = myVect.end();
            advance(itr1, (mid+1));
           // advance(itr2,(right-left)+1);
            
            Vector rightVect(itr1, itr2);
            
            //printVector(rightVect);
            head->right = makeTree(rightVect);
        }
        
        
        
        return head;
        
        
        
        
        
        
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode * head = makeTree(nums);
        
        return head;
        
        
        
    }
};