// Problem 283

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int next = 0;
        while(next < nums.size() && nums[next] != 0) next++;
        
        for(int i = 0; i < nums.size(); i++) {
            
            
            if(nums[i] != 0 && next < i) {
                
                swap(nums[i], nums[next]);
                while(next < nums.size() && nums[next] != 0) next++; 
                
            }
            
            //i = next + 1;
            
            
            
            
        }
        
    }
};