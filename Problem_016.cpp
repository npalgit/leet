// Problem 16

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        /*
        1. Simple Solution
        2. https://discuss.leetcode.com/topic/17215/c-solution-o-n-2-using-sort/2
        3. Sorting has to be done before. Otherwise, solution will be O(n^3)
        4. Solved in ARRAY
        5. Few Corner Cases as well.
        
        
        */
        
        if(nums.size() < 3) return 0;
        int j, k;
        int sum;
        
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        
        int i = 0;
        
        for(i = 0; i < nums.size()-2; i++){
           
            
            j = i + 1;
            k = nums.size()-1;
            
            while(j < k ){
                
                sum = nums[i] + nums[j] + nums[k];
                
                if(sum == target) return sum;
                if(abs(target - sum) < abs(target - closest)) closest = sum;
                else if(sum > target) k--;
                else if(sum < target) j++;
                
            }
            
        }
        
       
        
        return closest;
        
    }
};