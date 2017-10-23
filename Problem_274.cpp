// Problem 274


using namespace std;

typedef vector<int> Vector;
typedef unordered_map<int, int> HashMap;

class Solution {

public:

   
    int hIndex(vector<int>& citations) {
        
        // Solution 1: This is O(nlogn) solution
        
        /*
        if(citations.empty())return 0;
        
        sort(citations.begin(), citations.end());
        
        int hIndex = citations.size();
        
        for(int i = 0; i < citations.size(); i++) {
            
            
            
            if(citations[i] >= hIndex) return hIndex;
            else hIndex--;
            
            
        }
        
        return hIndex;
        
        */
        
        
        // Solution 2: This is O(n) time and O(n) space solution
        
        HashMap myMap;
        for(int i= 0; i <= citations.size(); i++){
            
            myMap[i] = 0;
        }
        
        
        for(int i= 0; i < citations.size(); i++){
            
            int candidate = citations[i];
            if(candidate > citations.size()) candidate = citations.size();
            
            myMap[candidate]++;
        }
        
        int cumSum = 0;
        for(int i = citations.size(); i >= 0; i--){
            
            
            cumSum = cumSum + myMap[i];
            
            if(cumSum >= i) return i;
            
            
        }
        
        return cumSum;
        
        
        
                
    }
};