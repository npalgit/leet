// Problem 357

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
     
     if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10; // should be 11
        }
        n = min(n, 10);
        int sum = 10;
        int tmp = 9;
        for (int i = 1; i < n; i++) {
            tmp *= 10 - i;
            sum += tmp;
            
            cout << "Temp = " << tmp << "  Sum = " << sum << endl;
        }
        return sum;
     
     
       
    }
};