// Problem 62

using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:
    int uniquePaths(int m, int n) {

        Matrix myTable;
        Vector row = Vector(n,1);
        
        for(int i = 0 ; i < m; i++) {
            
            myTable.push_back(row);
            
            for(int j = 0; j <n; j++){
                
               
                if(i != 0 && j != 0) myTable[i][j] = myTable[i-1][j] + myTable[i][j-1];
                
                
                
            }
        }
        
        return myTable[m-1][n-1];
    }
};