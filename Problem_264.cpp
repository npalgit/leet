// Problem 264

using namespace std;

typedef vector<int> Vector;
typedef priority_queue<long long, vector<long long>, greater<long long>> PQ;

class Solution {
public:
    int nthUglyNumber(int n) {
        
        /*
        1. A very easy DP Problem
        2. Also, non-linearity to be considered as we are using the min
        3. Done in DP Section
        
        
        */
              
        //Solution 1.
        if(n==1) return 1;
        
        Vector dp;
        dp.push_back(1);
        
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        
        int min_value;
        
        for(int i = 0; i <n-1; i++){
            
            min_value = min(2*dp[p2],min(3*dp[p3], 5*dp[p5]));
            
            //cout << "Min Value = " << min_value << endl;
            
            dp.push_back(min_value);
            
            if(min_value == dp[p2] *2)p2++;
            if(min_value == dp[p3] *3)p3++;
            if(min_value == dp[p5] *5)p5++;
            
        }
        
        return dp[dp.size()-1];
        
    }
};