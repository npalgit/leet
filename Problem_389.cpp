// Problem 389


class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char dummy = 'a';
        char result = dummy;
        
        for(char x : s) {
            
            result = result ^ x;
            
        }
        
        for(char x : t) {
            
            result = result ^ x;
            
        }
        
        

        return result ^ dummy;
        
        
    }
};