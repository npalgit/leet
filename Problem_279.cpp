// Problem 279

using namespace std;
#include<algorithm>

typedef vector<int> Vector;

class Solution {
public:
    int numSquares(int n) {
        
        
        
        /*
        
        1. Very easy problem
        2. DP is essential here. Recursive Solution will Fail.
        3. 
        
        
        
        */
        Vector dp;
        
        dp.push_back(0);
        dp.push_back(1);
        
        dp.push_back(2);
        dp.push_back(3);
        
        if(n<4) return dp[n];
        
        
        int rem;
        
        for(int i = 4; i <=n ; i++){
           
            int minNum = INT_MAX;
            
            for(int j = 1; j < sqrt(n) +2; j++){
                
                if(i - (j*j) < 0) break;
                
                rem = i - (j*j);
                
                minNum = min(minNum, 1 + dp[rem]);
                
            }
            
            dp.push_back(minNum);
        
        }
        
        /*
        for(int i = 0; i < dp.size(); i++){
            
            cout << "i = " << i << " : " << dp[i] << endl;
            
        }
        */
        
        return dp.back();
    }
};