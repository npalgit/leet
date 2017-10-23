// Problem 245

using namespace std;

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        
        int minDist = INT_MAX;
        int lastIndex = -1;
        
        int index_1 = INT_MAX;
        int index_2 = INT_MAX/2;
        
        for(int i = 0; i < words.size(); i++){
            
            if(word1 == word2){
                
                if(words[i] != word1)continue;
                if(words[i] == word1 ){
                    
                    if(lastIndex == -1) lastIndex = i;
                    else{
                        
                        minDist = min(minDist, abs(lastIndex - i));
                        cout << "Min Dist = " << minDist << endl;
                        lastIndex = i;
                    }
                    
                }
                
            }
            
            else {
                
            
                if(words[i] == word1) {
                    index_1 = i;
                    
                }
                
                
                if(words[i] == word2 ){
                    index_2 = i;
                    
                }
                
                
                minDist = min(minDist, abs(index_1 - index_2));
                
            }
            
        }
        
        return minDist;
        
    }
};