// Problem 64

#include<algorithm>
using namespace std;



typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        
        Vector row = Vector(cols, 0);
        Matrix myTable;
        int minValue;
        
        for(int i = 0; i < rows; i++) {
        
            myTable.push_back(row);
            
            for (int j =0; j < cols; j++){
                
                if(i==0 && j==0) myTable[i][j] = grid[i][j];
                
                else if(i == 0 && j != 0 ) myTable[i][j] = myTable[i][j-1] + grid[i][j];
                
                else if(i != 0 && j == 0) myTable[i][j] = myTable[i-1][j] + grid[i][j];
                
                else{
                    
                    minValue = min(myTable[i-1][j], myTable[i][j-1]);
                    
                    myTable[i][j] = minValue + grid[i][j];
                    
                }
                
            }
            
            
        }
        
        return myTable[rows-1][cols-1];
    }
};