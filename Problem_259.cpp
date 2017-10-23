// Problem 259

using namespace std;

typedef vector<int> Vector;

class Solution {
public:

  
    
    int threeSumSmaller(vector<int>& nums, int target) {
        
        
        /*
        
        1. This is indeed a thoughtful question
        2. Key Thing to notice is when and how to increment our count variable.
        
        */
        
        if(nums.size() < 3) return 0;
        
        sort(nums.begin(), nums.end());
        
        int count = 0;
        
        for(int i = 0; i < nums.size()-2; i++){
            
            for(int j = i+1; j < nums.size()-1; j++ ){
                
                
                int sum = nums[i] + nums[j];
                int k = nums.size()-1;
                
                while(j < k){
                    
                    if(nums[i]+ nums[j]+ nums[k] < target) {
                        
                        count = count + k - j;
                        j++;
                    }
                    else {
                        
                        k--;
                     
                        
                    }
                    
                    
                }
                
              
            }
            
            
            
        }
        
        return count;
        
    }
};