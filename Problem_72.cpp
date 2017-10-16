// Problem 72

using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:
    int minDistance(string word1, string word2) {


        /*
        int w1Size = word1.size();
        int w2Size = word2.size();
        
        Vector row(w2Size+1, 0);
        Matrix dp(w1Size+1, row);
        // Row Indices correspond to w1
        // Col Indices correspond to w2
        
        //cout << "Initializing" << endl;
        //cout << "DP Size = " << dp.size() << ", " << dp[0].size() << endl;
        
       for(int i = 1; i <= w1Size; i++) dp[i][0] = i;
       for(int j = 1; j <= w2Size; j++) dp[0][j] = j;
                
        //cout << "Initialized" << endl;
          
        
        for(int i = 1; i <= w1Size; i++){
            
            for(int j = 1; j<= w2Size; j++){
                
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    
                    dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j] +1, dp[i][j-1] +1));
                    
                }
                
                
            }
        }      
        
        
        return dp[w1Size][w2Size];
                
        */        
                
                
           
        // This Code is O(m) space
        // Above Code was O(mn) space
    
    
        int w1Size = word1.size();
        int w2Size = word2.size();
        
        int diagLeft = 0;
        
        int top = 1;
        int left = 1;
        
        Vector dp(w2Size+1, 0);
        
        
       //for(int i = 1; i <= w1Size; i++) dp[i][0] = i;
       for(int j = 1; j <= w2Size; j++) dp[j] = j;
                
        //cout << "Initialized" << endl;
          
        
        
        
        for(int i = 1; i <= w1Size; i++){
            
            
            diagLeft = dp[0];
            dp[0] = i;
            
            
            for(int j = 1; j<= w2Size; j++){
                
                top = dp[j];
                left = dp[j-1];
                
                // Characters Not Same
                if(word1[i-1] != word2[j-1]) 
                {
                    
                    
                    
                    
                    dp[j] = min(top+1, min(left+1, diagLeft+1));
                    
                    
                    
                }
                // Characters are Same
                else dp[j] = diagLeft;
                
                // Because j will increment, hence, we will move on to the next column
                // Current Top Element will become the Diagnol Left Element for the next column
                diagLeft = top;
                
                
            }
        }      
        
        
        return dp[w2Size];
                     
                
    
        
        
        
        
        
        
    }
};