// Problem 153

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        /*
        1. Very thoughtful question
        2. Only 2 cases to deal with:
            a. If left <= right, therefore this whole array is sorted. So just return the left element
            b. Else, Sorted Array is rotated
                i. go for the mid element
                ii. do binary search
        
        
        */
    
       

        int left = 0;
        int right  = nums.size()-1;
        
        while(left < right) {
            
            // Checking if the Array is rotated or not
            if(nums[left] <= nums[right]) return nums[left];
            
            // If the Array is rotated, apply the rule
            int mid  = left + (right - left)/2;
            
            if(nums[mid] >= nums[left] ) left = mid +1;
            
            else right = mid;
        
            /*
            cout << "Value at Mid = " << nums[mid] << endl;
            cout << "Value at Left = " << nums[left] << endl;
            cout << "Value at Right = " << nums[right] << endl;
            
            */
        
            
        }

        return nums[right];

    }
    
    
};