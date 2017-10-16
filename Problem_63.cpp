// Problem 63

using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:

    void printTable( Matrix & table){
        
        for(int i = 0; i < table.size(); i++){
            
            
            for(int j = 0; j < table[0].size(); j++){
                
                
                cout << table[i][j] << " : ";
            }
            
            cout << endl;
        }
        
        
        
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        

        /*
        
        1. Same as Unique Paths Problem
        2. Only if it is an obstacle, you cannot add, and replace it with zero to avoid addition from there on.
        3. O(mn) in time, where mn = size of grid.
        4. O(1) in space.
        
        
        */
        Vector row(obstacleGrid[0].size(), 0);
        
        
        obstacleGrid.insert(obstacleGrid.begin(), row);
        
        for(int i = 0; i < obstacleGrid.size(); i++){
            
            obstacleGrid[i].insert(obstacleGrid[i].begin(), 0);
        }
  
        
        obstacleGrid[1][0] = -1;
        
        
        //printTable(obstacleGrid);
        
        
        for(int i = 1; i < obstacleGrid.size(); i++){
            
            for(int j = 1; j < obstacleGrid[0].size(); j++){
                
                
                if(obstacleGrid[i][j] == 0) obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                
                if(obstacleGrid[i][j] == 1) obstacleGrid[i][j] = 0;
            }
            
        }
        
  
        //cout << endl << endl << endl;
        
        return (-1* obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]);
       // printTable(obstacleGrid);
        
        //return 0;
        
        
    }
};