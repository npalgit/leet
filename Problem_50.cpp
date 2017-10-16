// Problem 50

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        
     
    	double ans = 1;
    	
    	unsigned long long power;
    	double mult = x;
    	
    	if (n < 0) {
    		power = -n;
    		mult = 1 / mult;
    	} 
    	
    	else {
    		power = n;
    	}
    	
		while (power) {
		    
			if (power & 1) ans = ans * mult;
			
			mult  = mult * mult;
			power = power >>1;
		}
		
		return ans;
    
    }
};