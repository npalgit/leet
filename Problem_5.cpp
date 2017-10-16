// Problem 5

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        // Return if s is really short
        if (s.size() < 2) return s;
        
        
        int len = s.size();
        int maxLeft = 0;
        int maxLength = 1; 
        int left = 0, right = 0;
        
        for (int index = 0; index < s.size() ;) {
            
            left = index;
            right = index;
            
           // cout << "Index = " << index << ": " << s[index] << ", Left = " << left << ", Right = " << right << endl;
            
            
            // Skip Duplicate Characters
            while (right < len - 1 && s[right] == s[right + 1]){
                
                right++;
            
            }
            
            
            // Start from the Next Character
            index = right + 1;
            
           
            
            // Look for Palindrome Validity
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                
                right++;
                left--;
                
            }
            
            int currentLength  = right - left + 1;
            
            //cout << "Left = " << left << ", Right = " << right << ", Current Length  = " << currentLength << endl;
            
            // Finally, save the maximum Length only and binding it with its starting Left Index
            if (maxLength < currentLength) {
                
                maxLeft = left;
                maxLength = currentLength;
            
                
            }
            
            //cout << endl;
        }
        
        return s.substr(maxLeft, maxLength);
    }
        
    
};