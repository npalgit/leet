// Problem 35

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int left = 0;
        int right  = nums.size()-1;
        
        while(left < right){
            
            int mid = left + (right - left)/2 ;
            
            
            if(nums[mid] > target) right  = mid - 1;
            if(nums[mid] < target) left = mid + 1;
            if(nums[mid]  == target) return mid;
            
            
            
        }
        
        
        if(nums[right] > target) right--;
        if(nums[right] < target) right++;
        
        
        if(right < 0) return 0;
        if(right > nums.size()) return nums.size() -1;
        
        return right;
        
    }
};