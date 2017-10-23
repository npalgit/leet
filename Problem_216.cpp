// Problem 216

using namespace std;


typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:

    void combsTry(Matrix & result, Vector comb, int k, int n){
        
        
        if(k == 0 || n < 0) return;
        
        //cout << "Calling for k  = " << k << ",  n = " << n << endl; 
        
        
        if(k == 1 && n > comb.back() && n <= 9) {
            
            comb.push_back(n);
            result.push_back(comb);
            
            //for(auto x : comb) cout << x << " : ";
            //cout << endl;
            
            return;
        }
        
        
        for(int i = 1; i <=9; i++){
            
            if(comb.empty()) {
                
                comb.push_back(i);
                
                combsTry(result, comb, k - 1, n- i);
            
                comb.pop_back();
            }
            else{
                
                int last = comb.back();
                
                if(i > last){
                    
                    comb.push_back(i);
                    
                    combsTry(result, comb, k -1, n - i);
                    
                    comb.pop_back();
                    
                }
                
                else continue;
                
                
            }
            
            
            
        }
        
        return;
        
        
        
        
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        /*
        1. Simple BackTracking Solution.
        2. Just generate all cases
        3. Corner Cases :
            a. Remember to put continue and not return in else case
            b. Dealing with k = 0 and negative n  cases
        
        */
        
        Matrix result;
        
        Vector comb;
        
        combsTry(result, comb, k, n);
        
        
        return result;
    }
};