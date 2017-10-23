// Problem 313


using namespace std;

typedef vector<int> Vector;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {

        /*
        1. Again a DP problem
        2. Use another vector to collect the pointer increments of all primes.
        3. Done in DP Section
        
        */
        
        int size = primes.size();
        Vector current(size, 0);
        
       // cout << "Size = " << size << endl;
        
        Vector dp;
        dp.push_back(1);
        
        int min_value = INT_MAX, value = 0, index;
        
        for(int i = 0; i < n-1; i++){
            
            
            min_value = INT_MAX;
            
            for(int j = 0; j < size; j++) {
                
              
                
                index = current[j];
                
                value = dp[index] * primes[j];
                
                min_value = min(min_value, value);
                
            }   
            
            dp.push_back(min_value);
            
            for( int j = 0; j < size; j++){
                
                index = current[j];
                
                if( min_value == (dp[index] * primes[j]) ) current[j] = current[j] + 1;
                
            }
            
            
        }
        
        
        return dp[dp.size()-1];
        

        
    }
};