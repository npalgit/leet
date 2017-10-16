// Problem 33

using namespace std;

typedef vector<int> Vector;


class Solution {
public:


    int binSearch(Vector & nums, int target, int left, int right) {
    
        while(left<= right) {
            
            int mid = left + (right - left)/2;
            
            if(target > nums[mid]) left = mid + 1;
            else if(target < nums[mid]) right = mid - 1;
            else if(target == nums[mid]) return mid;
            
            
        }
        
        return -1;
    
    }
    
    
    int helpSearch(Vector & nums, int target, int left, int right) {
        
        
        
        // Case 1: Original Array is Sorted. No Rotation
        if(nums[right] >= nums[left]) return binSearch(nums, target, left, right);
        
        int mid  = left + (right - left)/2;
        
        // Case 2: Left Array is sorted. Break-Point lies in Right Array
        if(nums[mid] >= nums[left]) {
            
            // If Target lies in Left Array, do a Binary Search.
            // Else do a Help Search in Right Array
            if(target >= nums[left] && target <= nums[mid]) return binSearch(nums, target, left, mid);
            else return helpSearch(nums, target, mid+1, right);
            
            
        }
        
        // Case 3: Right Array is sorted. Break-Point lies in Left Array
        else {
            
            
            // If Target lies in Right Array, do a Binary Search.
            // Else do a Help Search in Left Array
            if(target >= nums[mid] && target <= nums[right]) return binSearch(nums, target, mid, right);
            else return helpSearch(nums, target, left, mid-1);
            
            
        }
    }

    int search(vector<int>& nums, int target) {
        
        if(nums.empty()) return -1;
        
        int result = helpSearch(nums, target, 0, nums.size()-1);
        
        return result;
        
    }
};