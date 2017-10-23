// Problem 371

class Solution {
public:
    int getSum(int a, int b) {
        
        if(b == 0) return a;
        else {
            
            int diffBits = a ^ b;
            
            int sameBits = a & b;
            
            sameBits = sameBits << 1;
            
            return getSum(diffBits, sameBits);
            
        };
        
    }
};