// Problem 40

using namespace std;


typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {


public:


    void combSum(Vector & candidates, Vector partial, Matrix & result, int target, int start){
        
        /*
        1. Simple BackTracking Solution
        2. Sorting of elements is necessary before
        3. Solved in ARRAY section
        4. Deals with 1 specific corner case of repeated elements
        
        */
        
        if(target < 0) return;
        if(target == 0) {
            
            result.push_back(partial);
            return;
            
        }
        
        int runSum = 0;
        
        for(int i = start; i < candidates.size(); i++){
            
            
                // Very Important Condition
                // Learn this Condition
                if(i && candidates[i] == candidates[i-1] && i > start) continue;
                    
                
                
                partial.push_back(candidates[i]);
                combSum(candidates, partial, result, target - candidates[i], i+1);
                partial.pop_back();
                
            
            
        }
        
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        Matrix result;
        Vector partial;
        
        sort(candidates.begin(), candidates.end());
        combSum(candidates, partial, result, target, 0);
        
        return result;
        
        
    }
};