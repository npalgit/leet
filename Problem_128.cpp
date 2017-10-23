// Problem 128

using namespace std;

typedef set<int> Set;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        
        /*
        1. This is in Hard category but requires only little thinking.
        2. Key thing to visualize is the requirement of a data structure as we have to do it in linear time.
        
        */
        
        Set mySet;
        for(auto x : nums) mySet.insert(x);
        
        int best = 0;
        int current = 0;
        
        for(auto x : mySet){
            
            if(mySet.find(x-1) == mySet.end()){
                
                current = 0;
                while(mySet.find(x) != mySet.end()){
                    
                    current++;
                    x++;
                }
                
            }
            
            else continue;
            
            best = max(best, current);
            
            
            
        }
        
        return best;
    }
};