// Problem 238

using namespace std;

typedef vector<int> Vector;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        /*
        1. Very easy solution
        2. There is just a trick to exclude the current number
        3. See the Notes
        4. Done in ARRAY
        
        */
        
        if(nums.empty()) return nums;
        
        
        
        Vector result(nums.size(), 1);
        
        for (int i = 1; i < nums.size(); i++){
            
            result[i] = result[i-1] * nums[i-1];
            
        }
        
        int mult_factor = 1;
        
        for (int j = nums.size()-2; j >=0; j--){
            
            mult_factor = mult_factor * nums[j+1];
            result[j] = result[j] * mult_factor;
            
        }
    
        return result;
    
    }
};