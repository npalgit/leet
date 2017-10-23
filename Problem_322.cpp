// Problem 322

using namespace std;

typedef vector<int> Vector;
typedef Vector::iterator VectorItr;

class Solution {

public:

    void printVector(Vector & T) {
        
        
        for(auto x : T) cout << x << " : " ;
        cout << endl;
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
    
    
        /*
        1. Very easy DP Problem
        2. Detailed Explanation in Pages
        
        
        */
        int minCoin = INT_MAX;
        for(int k = 0; k < coins.size(); k++){
            
            minCoin = min(minCoin, coins[k]);
        }
        int maxCoin = amount / minCoin;
        
        //cout << "Min Coin = " << minCoin << endl;
        //cout << "Max Coins = " << maxCoin << endl;
        
        Vector T(amount+1, maxCoin + 100);
        T[0] = 0;
        
        Vector coinIndex(amount+1, -1);
        //cout << "Initial T Vector = " << endl;
        //printVector(T);
        int value;
        
        for(int j = 0; j < coins.size(); j++){
            
            
            for(int i = 0; i < T.size(); i++){
                
                if((i - coins[j]) >=0 ) value = 1 + T[i - coins[j]];
                else value = T[i];
                
                T[i] = min(T[i], value );
                T[i] = abs(T[i]);
                
            }
           // cout << endl << "After Coin of = " << coins[j] << endl;
           // printVector(T);
        }
        
        //printVector(T);
        
        if(T[amount] > maxCoin) return -1;
        else return T[amount];
        
        
        //return 0;
    }
};