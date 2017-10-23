// Problem 254

using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:

    void printVector(Vector & myVect){
        
        
        for(auto x: myVect){
            
            cout << x << " : "; 
        }
        
        cout << endl;
    }
    
    void getResult(Matrix & result, Vector & row, int n){
        
        /*
        
        1. Simple BackTracking Problem
        2. Key thing to notice is the use of Square Root in the problem.
        3. Another thing to notice how push and pop happens in the Vectors.
        
        */
        
            int i;
            
            
            
            if(row.empty()) i = 2;
            else i = row.back();
            
            //printVector(row);
            
            while(i <= sqrt(n)) {
                
                if(n%i==0){
                    
                    row.push_back(i);
                    row.push_back(n/i);
                    
                    //printVector(row);
                    //cout << "Pushing the Result" << endl;
                    
                    result.push_back(row);
                    
                    row.pop_back();
                    
                    getResult(result,row,n/i);
                    
                    row.pop_back();
                }
                
                i++;
                
            }
        }
        
        
    vector<vector<int>> getFactors(int n) {
        
        Matrix table;
        Vector row;
        
        getResult(table,row,n);
        
        return table;
        
    }
};