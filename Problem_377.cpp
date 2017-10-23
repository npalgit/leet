// Problem 377

using namespace std;

typedef vector<int> Vector;
typedef unordered_map<int, int> HashMap;

class Solution {
public:

    int helpCombs(HashMap & myMap, Vector & nums, int target){
        
        
        if(nums.empty() || target < 0) return 0;
        if(target == 0) return 1;
        int count  = 0;
        
        if(myMap.find(target) != myMap.end()) return myMap[target];
        
        for(auto num: nums){
            
            
            count = count  + helpCombs(myMap, nums, target - num);
            
        }
        
        myMap[target] = count;
        return count;
        
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        
       
        /*
        1. There are similar Combination sum problems - 40, 216
        2. Mostly all of them use Backtracking Solution
        3. Here, we observe same problem being solved again and again. Hence, we use DP.
        
        */
       
        HashMap myMap;
        int result = helpCombs(myMap, nums, target);
        
        
        return result;
        
        
        
    }
};