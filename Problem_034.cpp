// Problem 34

using namespace std;

typedef vector<int> Vector;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        /*
        1. Another Binary Search Variant Question
        2. Corner Case Dealing extremely important over here.
        3. Solved in ARRAY.
        
        */
        
        Vector result(2, -1);
        
        if(nums.empty()){
            
                      
            return result;
            
        }
        
        int left = 0;
        int right = nums.size()-1;
        
        int mid;
        
        while(left < right){
            
            mid = left + (right - left)/2;
            
            if(nums[mid] < target) left = mid + 1;
            else right = mid;
            
        }
        
        if(nums[right] != target) return result;
        else result[0] = left;
        
        
        right = nums.size() - 1;
        
        while(left < right) {
            
            mid = left + (right - left)/2 + 1;
            
            if(nums[mid] > target) right = mid - 1;
            else left = mid ;
            
            
        }
        
        
        if(nums[right] == target) result[1] = right;
        
        return result;
        
    }
};