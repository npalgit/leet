// Problem 69
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
  
        if(x==0) return 0;
        long r = x;
        
        while(r > x/r){
            
            r = (r + x/r)/2;
        }
        
        return r;
    }
    
};