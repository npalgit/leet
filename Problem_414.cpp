// Problem 414

using namespace std;

typedef set<int> Set;

class Solution {
public:

    
    int thirdMax(vector<int>& nums) {
        
        
        Set mySet;
        
        for(auto x : nums){
            
            mySet.insert(x);
            
            if(mySet.size() > 3){
                
                mySet.erase(mySet.begin());
                
            }
            
        }
        
        //printSet(mySet);
        
        
        if(mySet.size() == 3) return *mySet.begin();
        else return *(--mySet.end());
    
        
        
        
    }
};