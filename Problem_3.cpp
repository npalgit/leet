// Problem 3

using namespace std;

typedef set<char> Set;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        Set mySet;
        
        int left = 0;
        int right = 0;
        int maxLength = 1;
        
        if(s.empty()) return 0;
        
        mySet.insert(s[0]);
        right++;
        
        while(left < right && right < s.size()){
            
            if(mySet.find(s[right]) == mySet.end()){
                
                mySet.insert(s[right]);
                right++;
            }
            
            else {
                
                char repeat = s[right];
                
                while(s[left] != s[right]){
                    
                            
                    mySet.erase(s[left]);
                    left++;
                    
                }
                
                left++;
                
                mySet.insert(s[right]);
                right++;
                
            }
            
            int setSize = mySet.size();
            maxLength = max(maxLength, setSize);
            
            //cout << "Left = " << left << ", Right  = " << right << endl;
           //cout << "Set Size = " << setSize << ", Max Length  = " << maxLength << endl; 
            
            
        }
        
        return maxLength;
        
    }
};