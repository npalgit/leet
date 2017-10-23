// Problem 96

using namespace std;

typedef vector<int> Vector;

class Solution {
public:

    
    int numTrees(int n) {
        
        Vector vect;
        vect.push_back(1);
        vect.push_back(1);
        int sum;
        
        for(int i = 2; i <=n;i++){
            
            sum = 0;
            for(int j = 1; j <= i; j++){
                
                sum = sum + (vect[j-1] * vect[i-j]);
                
                
            }
            
            vect.push_back(sum);
            
        }
        
     
        return vect.back();
    }
};