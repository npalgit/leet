// Problem 392

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        
        if (s.empty()) return true;
        /*
        for (int j = 0, i = 0; j < t.length(); j++) {
            if (s[i] == t[j] && ++i == s.length()) { return true; }
        }
        
        return false;
        
        */
        
        
        int start = 0;
        int end = 0;
        
        int i = 0;
        string temp;
        char ch;
        
        do{
            
           
           string temp(1, s[i]);
           
           
           
           end = t.find(temp, start);
           start = end + 1;
           
           //cout << "String = " << temp << ", Start = " << start << ", End = " << end << endl;
           
           i++;
           
           //cout << "i = " <<i << endl;
           
           
            
            
        }
        while(end != -1 && i < s.size());
        
        
        if(i == s.size()  && end != -1) return true;
        return false;
        
    }
};