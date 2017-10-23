// Problem 461


class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int xorResult = x ^ y;
        
        int distance = 0;
        //cout << "Xor Result = " << xorResult << endl;
        while(xorResult) {
            
            distance++;
            xorResult = xorResult & (xorResult -1 );
        }
        
        return distance;
    }
};