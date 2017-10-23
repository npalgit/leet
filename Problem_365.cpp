// Problem 365


class Solution {
public:

    
    /*
    int gcd(int x, int y){
        
        int maxNum;
        while(x != y && x != 1 &&  y != 1) {
            
            maxNum = max(x,y);
            
            if(maxNum == x) x = x - y;
            else y = y - x;
            
        }
        
        if(x == 1 || y == 1) return 1;
        return x;
    }
    */
    
    int gcd(int x, int y)
    {
         return y == 0 ? x : gcd(y, x % y);
    }

    
    bool canMeasureWater(int x, int y, int z) {
        
        
        if(z == 0) return true;
        if(z > x + y) return false;
        
        return (z % gcd(x,y) == 0);
        
        
}
        
    
};