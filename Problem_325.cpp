// Problem 325


using namespace std;

typedef map<int, int> HashMap;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        /*
        1. This is not a MEDIUM problem in terms of thinking
        2. Try to remember the 3 if cases.
        
        */
        
        HashMap myMap;
        
        int sum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            sum = sum + nums[i];
            
            
            if(sum == k) maxLen = i + 1;
            
            if(myMap.find(sum) == myMap.end()){
                
                myMap[sum] = i;
                
            }    
            
            
            if(myMap.find(sum - k) != myMap.end()){
                
                maxLen = max(maxLen, i - myMap[sum - k]);
                
            }
            
        
        }
        
        return maxLen;
        
    }
};

