// Problem 1.cpp

using namespace std;

typedef vector<int> Vector;
typedef unordered_map<int, int> HashMap;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        
        Vector answer;
        HashMap myMap;
        
        
        for(int i = 0; i < nums.size(); i++){
            
            
                
                if(myMap.find(nums[i]) == myMap.end()) myMap[nums[i]] = i;
                
                int complement = target - nums[i];
                if(myMap.find(complement)!= myMap.end() && i != myMap[complement]){
                    
                    answer.push_back(i);
                    answer.push_back(myMap[complement]);
                    return answer;
                    
                }
            
        }
        
        
        
        return answer;
    }
};