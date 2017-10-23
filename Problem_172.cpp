// Problem 172

class Solution {
public:

    
    int trailingZeroes(int n) {
        
        int count = 0;
        long int fivePow = 5;
        
        int quo = n/fivePow;
      
        
        while(quo > 0) {
            
            
            quo = n/fivePow;
            
            fivePow = fivePow * 5;
            count = count + quo;
            
            
        }
        
        
        return count;
        
    
            
    
    }
};