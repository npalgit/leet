// Problem 53

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        
            /*
            
             KADANE'S ALGORITHM
             1. See the page for details
            
            
            */
            
            if(nums.size() == 1) return nums[0];
            
            int totalMax = nums[0];
            int currMax = nums[0];
            
            for(int i = 1; i < nums.size(); i++){
                
                currMax = max(currMax + nums[i], nums[i]);
                totalMax = max(currMax, totalMax);
                
                
            }
    
        return totalMax;        
    }
    
};