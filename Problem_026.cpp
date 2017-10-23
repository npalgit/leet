// Problem 26

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        /*
        1. This is just an in-place Replace Problem
        
        */
        
        if(nums.empty()) return 0;
        
        
        int unique = 1;
        if(nums.size() == 1) return unique;
        
        for(int i = 1; i < nums.size(); i++) {
            
            int currElem = nums[unique-1];
            
            if(nums[i] == currElem) continue;
            else {
                
                nums[unique] = nums[i];
                unique++;
                
            }
        }
        
        return unique;
        
    }
};