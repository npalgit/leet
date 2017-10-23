// Problem 81

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
    
    
   
    bool search(vector<int>& nums, int target) {
        
        /*
        1. Classic case of all cases generation
        2. See the Notes
        3. If Rotation Point in Left Part of Mid:
        
            a. If Target  is less than  Mid-Point:
                i. Move Left
                
            b. If Target is greater than Mid-Point:
                i. If Target is greater than LeftMost Point:
                    * Move Left
                ii. If Target is less than LeftMost Point:
                    * Move Right
                    
        4. Similarly for the Right Part of Mid
        
        
        */
        
        int left = 0, right = nums.size() - 1;
  
        while (left <= right) {
            
            
            int mid = left + (right - left) / 2;
            
            // checking for Mid-Point being equal to target before
            if(nums[mid] == target) return true;
            
            if(nums[left] < nums[mid]){// Rotation Point in Right part of Mid
                
                
                // Move Right
                if(target < nums[left] || target > nums[mid]) left = mid + 1;
                else right= mid - 1; // Move Left
                
            }
        
            else if(nums[left] > nums[mid]){ // Rotation Point in Left Part of Mid
            
                // Move Left
                if(target < nums[mid] || target > nums[right]) right = mid -1;
                else left = mid + 1; // Move Right
                
            }
            
            else{
                
                // nums[mid] is not equal to Target. so LeftMost Point is also not the Target
                // Wee can only move the left pointer ahead
                // this can cause O(n) in the worst case
           
                 left ++;
            }
        
        }
        
        return false;
        
    }
};