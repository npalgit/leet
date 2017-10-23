// Problem 123

using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:
    int maxProfit(vector<int>& prices) {


        /*
        1. LEARN the problem
        2. Detailed Solution in Notes
        3. Solved in ARRAY.
        
        */

        if(prices.empty()) return 0;
        
        Vector blank(prices.size(), 0);
        
        int k = 2;
        Matrix table(k+1, blank);
        
        //cout << "Table Size = " << table.size() << ", " << table[0].size() << endl;
        
        int maxDiff = 0;
        
        for(int i  = 1; i < table.size(); i++){
            
            maxDiff = INT_MIN;
            
            for(int j = 1; j < table[0].size(); j++){
                
                maxDiff = max(maxDiff, table[i-1][j-1] - prices[j-1]);
                
                table[i][j] = max(table[i][j-1],  prices[j] + maxDiff);
                    
                
            }
            
            
        }
        
      //  cout << " Out of printing table" << endl;
        
      //  for(auto x: table){
            
      //      for(auto y : x) cout << y << " : ";
      //      cout << endl;
       // }
        
        //cout << endl;
        
    
    
    //cout << "Out of second print " << endl;
    return table[k][prices.size()-1];
    
    
    }
    
    
};