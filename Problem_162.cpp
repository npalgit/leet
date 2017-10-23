// Problem 162

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        /*
        1. Very simple Binary Seach Solution
        2. Solved in ARRAY
        
        */
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right ){
            
            int mid = left + (right - left)/2;
            
            int midElem = nums[mid];
            
            if(nums[mid] < nums[mid+1]) left = mid+1; // Right Element is higher in value
            
            else right = mid;   // Left Element is higher or equal in value
            
        }
        
        return left;
        
    }
};