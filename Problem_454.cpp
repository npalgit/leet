// Problem 454

using namespace std;

typedef vector<int> Vector;
typedef map<int, int> HashMap;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        
        /*
        1. This is an easy code proble
        2. Main thing to think is that it can be broken down into 2 simpler problems
        3. This is the beauty of Data Structures
        4. No Major Corner Cases. Logic  is much more important in these problems.
        
        
        */
        
        HashMap mySet;
        int result = 0;
        
        for(int i = 0; i < A.size(); i++){
            
            for(int j = 0; j < B.size(); j++){
                
                int sum = A[i] + B[j];
                if(mySet.find(sum) == mySet.end()){
                    
                    mySet[sum] = 1;
                }
                else mySet[sum]++;
            }
        }
        
        
        for(int i = 0; i < C.size(); i++){
            
            for(int j = 0; j < D.size(); j++){
                
                int sum = C[i] + D[j];
                sum = sum * -1;
                if(mySet.find(sum) != mySet.end()) result = result + mySet[sum];
                
            }
        }


        return result;

    }
};