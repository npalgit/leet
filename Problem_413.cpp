// Problem 413


using namespace std;

typedef vector<int> Vector;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        /*
        
        1. Logic is more important in this question 
        2. See and understand the logic first
        3. Solved in DP and MATHS Section
        
        */
        
        if(A.size() < 3) return 0;
        
        Vector diff;
        int currDiff = A[2] - A[1];
        int lastDiff = A[1] - A[0];
        
        diff.push_back(0);
        diff.push_back(0);
        
        for(int i = 2; i < A.size(); i++){
            
            // To maintain constance space complexity
            if(diff.size() > 5) diff.erase(diff.begin());
            
            
            currDiff = A[i] - A[i-1];
            
            if(lastDiff == currDiff){
                
                // Understand where this equation came from
                int sum = diff.back() - diff[diff.size()-2] + 1 + diff.back();
                
                diff.push_back(sum);
                
            }
            
            else{
                
                diff.push_back(diff.back());
            }
            
            
            lastDiff = currDiff;
            
            
        }
        
        
        return diff.back();
        
    }
};