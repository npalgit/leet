// Problem 372

using namespace std;

class Solution {
public:

    const int base = 1337;
    
    int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10
    {
        a %= base;
        int result = 1;
        for (int i = 0; i < k; ++i)
            result = (result * a) % base;
        return result;
    }
    
    
    int superPow(int a, vector<int>& b) {
        
        
        /*
        1. This is just pure Maths
        2. Just see the solution in the Solved Notes
        3. Solved in MATHS.
        
        
        */
        
        if(b.empty()) return 1;
        
        int lastDigit = b.back();
        
        b.pop_back();
        
        return powmod(superPow(a, b), 10) * powmod(a, lastDigit) % base;
    
    
        
    }
};