// Problem 47

using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:


    void permute(Vector nums, Matrix & result, int iter, int org_size){
        
        
        /*
        1. Solved in BACKTRACKING
        2. Swapping is a good technique for Permutation
        3. Dealing with Duplicate elements is also important
        
        */
        
        if(iter == org_size - 1){
            result.push_back(nums);
            return;
            
        }
        
        for(int k = iter; k < org_size; k++){
            
            if(k != iter && nums[k] == nums[iter]) continue;
            
            swap(nums[iter], nums[k]);
            
            permute(nums, result, iter+1, org_size);
            
            
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        Matrix result;
        sort(nums.begin(), nums.end());
        
        int org_size = nums.size();
        
        permute(nums, result, 0, org_size);
        
        return result;
        
        
    }
    
    
    
};