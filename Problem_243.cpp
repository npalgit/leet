// Problem 243

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        
        
        int minDist = INT_MAX;
        
        int index_1 = INT_MAX/2;
        int index_2 = INT_MAX;
        
        for(int i = 0; i < words.size(); i++){
            
            
            if(words[i] == word1) {
                
                index_1 = i;
            }
            
            
            if(words[i] == word2){
                
                index_2 = i;
                
            }
            
            //cout << "Index 1 = " << index_1 << " : " << "Index 2 = " << index_2 << endl;
            minDist = min(minDist, abs(index_1 - index_2));
            
        }
        
        return minDist;
        
        
    }
};