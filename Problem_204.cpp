// Problem 204

using namespace std;

typedef vector<int> Vector;
typedef Vector::iterator VectorItr;

class Solution {
public:

    
    int countPrimes(int n) {
        // SIEVE OF ERATOSTHENES
        
        // This prime Vector is initialized with 1 values
        Vector prime(n, 1);
        int k ;
        int sum = 0;
        for(int i = 2; i < ceil(sqrt(n)); i++){
            
            if(prime[i]){
                
                // k is the multiplacating factor here
                // i is the prime number we are testing for
                
               k = 2;
               while(k * i < n){
                   
                   prime[k*i] = 0;
                   k++;
                   
               }
                
            }
        }
        
        for(int i = 2; i < n; i++){
            
            sum = sum + prime[i];
        }
        
        return sum;
        
        
        
        
        
        
        
    }
};