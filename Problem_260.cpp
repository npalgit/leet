// Problem 260

typedef vector<int> Vector;
typedef unordered_map<int, int> HashMap;
typedef HashMap::iterator HashItr;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        HashMap myMap;
        
        Vector result;
        
        for(int i = 0; i < nums.size(); i++){
            
            int num = nums[i];
            
            myMap[num]++;
            
            
            
        }
        
        for(auto x: myMap){
            
            if(x.second <=1) result.push_back(x.first);
            
        }
        
        return result;
        
        
        
    }
};