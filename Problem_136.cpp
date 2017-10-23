// Problem 136

using namespace std;

typedef unordered_map<int, int> HashMap;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        /*
        HashMap myMap;
        
        for(auto x: nums){
            
            if(myMap.find(x) != myMap.end()){
                
                myMap.erase(x);
                
            }
            
            else myMap[x] = 1;
            
        }        
        
        return myMap.begin()->first;
        
        */
        
        
        
        int result = 0;
        
        for(auto x :nums){
            
            result = result ^ x;
        }
        
        return result;
    }
};