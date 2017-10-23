// Problem 343

class Solution {
public:
    int integerBreak(int n) {
        
        
        if(n <=2 ) return 1;
        else if(n == 3) return 2;
        
        else if(n%3  == 0) return pow(3, n/3);
        
        else if (n%3 == 2) return pow(3, (n-2)/3)*2;
        
        return pow(2, 2) * pow(3, (n-4)/3) ;
        
        return 0;
    }
};