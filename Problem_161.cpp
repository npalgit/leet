// Problem 161

using namespace std;


class Solution {
public:

    bool helpCompare(string &shortString, string &longString){
        
      
        
        int i = 0, j = 0;
        int mismatch = 0;
        
        while(i < shortString.size() && j < longString.size()){
            
            if(shortString[i] == longString[j]){
                
                i++;
                j++;
            }
            
            else {
                
                mismatch++;
                j++;
            }
            
            
        }
        
        // If no mismatch occured after full traversal of shorter String
        // Because, longer string just had 1 extra character at the end
        // and rest was same as shorter string
        if(mismatch == 0 && i ==j && j== longString.size()-1) return true;
        
        if(mismatch == 1) return true;
        else return false;
        
        
    }
    bool isOneEditDistance(string s, string t) {
        
        
        if(s == t) return false;
        
        if(s.size() == t.size()){
            
            int mismatch = 0;
            for(int i = 0; i < s.size(); i++){
                
                if(s[i] != t[i]) mismatch++;
                
                
            }
            
            if(mismatch == 1) return true;
            else return false;
            
        }
        
        if(s.size() - t.size() == 1) return helpCompare(t, s);
        else if(t.size() - s.size() == 1) return helpCompare(s, t);
        
        
        return false;
            
            
            
            
            
            
        
        
    }
};