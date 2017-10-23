// Problem 275

class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int hIndex = citations.size();
        
        for(int i = 0; i < citations.size(); i++) {
            
            
            
            if(citations[i] >= hIndex) return hIndex;
            else hIndex--;
            
            
        }
        
        return hIndex;
        
    }
};