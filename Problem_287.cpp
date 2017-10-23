// Problem 287

using namespace std;

typedef vector<int> Vector;
class Solution {
public:

    int modifiedBinSearch(Vector & nums) {
        
        int left = 0;
        int right = nums.size()-1;
        
        while(left < right) {
            
            int mid  = left + (right - left)/2;
            
            int count = 0;
            
            // We start incrementing count from left
            // Ideally if no duplicate exists, count would be equal to mid
            for(auto x : nums) {
                
                if(x <= mid) count++;
            }
            
            // Duplicate number exists in the Left Sub-Array. Decrement right pointer
            if(count > mid) right = mid;
            // Duplicate number exists in the Right Sub-Array. Increment left pointer
            else left = mid + 1;
            
            
        }
        
        return left;
        
    }
    int findDuplicate(vector<int>& nums) {
        
        /*
        int result = modifiedBinSearch(nums);
        
        return result;
        */
        
        // Cycle Detection in the Linked List
        if (nums.size() > 1)
	    {
    		int slow = nums[0];
    		int fast = nums[nums[0]];
    		
    		while (slow != fast)
    		{
    			slow = nums[slow];
    			fast = nums[nums[fast]];
    		}
    
    		fast = 0;
    		while (fast != slow)
    		{
    			fast = nums[fast];
    			slow = nums[slow];
    		}
    		return slow;
	    }
	
	    return -1;
    }
};