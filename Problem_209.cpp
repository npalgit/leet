// Problem 209

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        /*
        
        1. Considering all the possible continuous sub-arrays
        2. Considering their sum, and the minimum elements required to build that sum
        3. Solved in ARRAY.
        
        */
        
        int left = 0;
        int right = 0;
        int total = 0;
        int minLen = nums.size() + 1;

        while (right < nums.size()) {
            
            
            
            do {
                
                total = total + nums[right];
                right++;
                
            } 
            while (right < nums.size() && total < s);
            
            
            
            
            while (left < right && total - nums[left] >= s) {
                
                total = total - nums[left];
                left++;
            
            }
            
            
            
            if (total >= s) minLen = min(minLen, right - left);
            
            
        }
        
        
        if(minLen <= nums.size()) return minLen;
        else return 0;
    
        
    }
};