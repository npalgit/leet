// Problem 476

class Solution {
public:
    int findComplement(int num) {
        
        int zeroBits = __builtin_clz(num);
        int msb = 32 - zeroBits;
        //cout << "MSB = " << msb << endl;
        
        int mask = 0;
        while(msb){
            
            mask = (mask << 1) + 1;
            msb--;
        }
        
        
        int invert = ~num;
        int result = invert & mask;
        
        
        //cout << "Result = " << result << endl;
       // cout << "MSB = " << msb << endl;
        //cout << "Mask = " << mask << endl;
        
        
        
        
        return result;
        
    }
};