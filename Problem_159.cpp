// Problem 159

using namespace std;


typedef unordered_map<char, int> HashMap;

class Solution {
public:

    int lengthOfLongestSubstringKDistinct(string s, int k) {
        
        
        HashMap myMap;
        int answer = 0;
        int candidate = 0;
        
        int left = 0, right  = 0;
        int counter = 0;
        
        /*
        for(auto x : myMap){
            
            myMap[x]++;
        }
        
        */
        
        while(right < s.size()){
            
            
            if(myMap[s[right++]]++ == 0) counter++;
            
            while(counter > k) {
                
                if(myMap[s[left++]]-- == 1) counter--;
            
                
            }
            
            answer = max(answer, right - left);
            
            
            
            
            
            
        }
        
        return answer;
        
    }
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        return lengthOfLongestSubstringKDistinct(s, 2);
        
    }
};