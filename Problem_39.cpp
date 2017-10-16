// Problem 39

using namespace std;
class Solution {
typedef vector<int> Vector;
typedef vector<Vector> Matrix;

public:

    void tryComb(Vector & candidates, int target, Vector &row, Matrix & result){
        
        
        /*
        1. Form a tree structure.
        2. Try out all the solutions.
        3. Recursive Tree Structure.
        4. Corner Cases:
            a. Returning when target is less than zero.
            b. condition on when to call the function
            c. Remember to pop back from the row
        
        
        */
        
        if(target < 0) return;
        if(target == 0){
            
            result.push_back(row);
        }
        int lastElem;
        
        for(int i = 0; i < candidates.size(); i++){
            
                //row.clear();
                if(row.empty()==1) {
                    row.push_back(candidates[i]);
                    if((target - candidates[i]) >= 0)tryComb(candidates, target - candidates[i], row, result);
                    row.pop_back();
                }    
            
                else{
                    
                   lastElem = row.back();
                   if(candidates[i] >= lastElem && target >= candidates[i] ){
                       row.push_back(candidates[i]);
                       
                       tryComb(candidates, target - candidates[i], row, result);
                       row.pop_back();
                   }
                    
                }
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        Matrix result;
        Vector row;
        
        tryComb(candidates, target, row, result);
        
        return result;
        
    }
};