//Problem 266

using namespace std;

typedef unordered_map<char, int> HashMap;


class Solution {
public:
    bool canPermutePalindrome(string s) {
            
        HashMap myMap;
        
        for(int i = 0; i < s.size(); i++) {
            
            myMap[s[i]]++;
            
        }
        
        int oddElems = 0;
        
        for(auto x : myMap){
            
            if(x.second % 2 ) oddElems++;    
            
        }
        
        if(oddElems == 0 || oddElems == 1) return true;
        return false;
    }
};