// Problem 152

using namespace std;

#include<algorithm>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        /*
        1. O(1) space , O(n) time
        2. Very easy problem
        3. It is a DP problem as can be broken down into problems solution till last element
        4. See page for details 
        
        */
        
        if (nums.size()== 0) {
        return 0;
    }
    
    int maxherepre = nums[0];
    int minherepre = nums[0];
    int maxsofar = nums[0];
    int maxhere, minhere;
    
    for (int i = 1; i < nums.size(); i++) {
        
        maxhere = max(max(maxherepre * nums[i], minherepre * nums[i]), nums[i]);

        minhere = min(min(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
        
        maxsofar = max(maxhere, maxsofar);
        
        maxherepre = maxhere;
        
        minherepre = minhere;
    }
    
    return maxsofar;
        
    }
    
    
};