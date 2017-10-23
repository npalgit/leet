
// Problem 268

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        
        int sum = 0;
        
        
        for(int i = 0; i < nums.size(); i++){
            
            sum = sum + nums[i];
            
        }
        
        int n = nums.size();
        int size_sum = n*(n+1)/2;
       
        
       
        
        return size_sum - sum;
        
        
        /*
        
        int len = nums.size();
    int sum = (0+len)*(len+1)/2;
    for(int i=0; i<len; i++)
        sum-=nums[i];
    return sum;
    
    */
        
    }
};