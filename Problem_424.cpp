// Problem 424


using namespace std;

typedef vector<int> Vector;
class Solution {
public:

    
    
    int characterReplacement(string s, int k) {
        
        /*
        1. Indeed, a tough problem
        2. Understand the Sliding window Approach
        */
        
        Vector count(26,0);
        
        int maxCount = 0, maxLength = 0;
        
        int i = 0;
        
        for(int j = 0; j < s.size(); j++){
            
           
            maxCount = max(maxCount, ++count[s[j] - 'A']);
            
            int winSize = j - i + 1;
            int error = winSize - maxCount;
    
            
            if(error > k){
             
                count[s[i] - 'A']--;
                i++;
                
            }
            
            maxLength = max(maxLength, j - i + 1);
            
        }
        
        return maxLength;
    }
};