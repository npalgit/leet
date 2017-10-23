// Problem 280


using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        /*
        1. Simple Logic
        2. Just go by the fundamentals
        
        
        */
        
        if(nums.empty()) return;
        for(int i = 0; i < nums.size()-1; i++){
            
            // Swap even-indexed element if it is greater than next element
            if(i%2 == 0 && nums[i] > nums[i+1]){
                
                swap(nums[i], nums[i+1]);
            } 
            
            // Swap odd-indexed element if it is lesser than the next element
            if(i%2 != 0 && nums[i] < nums[i+1]){
                
                swap(nums[i], nums[i+1]);
            }
        }
        
       
        
    }
};