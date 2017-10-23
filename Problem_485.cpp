// Problem 485


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int currCount = 0;
        int maxCount = 0;
        
        if(nums.empty()) return maxCount;
        if(nums[0]) {
            
            currCount = 1;
            maxCount = 1;
            
        }
        for(int i = 1; i < nums.size(); i++){
            
            if(nums[i] == 1) {
                
                if(currCount == 0) {
                    
                    currCount++;
                    maxCount = max(maxCount, currCount);
                    continue;
                    
                }
                
                else if(currCount && nums[i] == nums[i-1]) {
                    
                    currCount++;
                    
                    
                }
                
                maxCount = max(maxCount, currCount);
                
            }
            
            else currCount = 0;
            
            
        }
        
        
        return maxCount;
    }
};