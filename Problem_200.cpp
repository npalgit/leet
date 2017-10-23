// Problem 200

using namespace std;

typedef vector<char> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:
    
    void dfs(int row, int col, Matrix & grid){
        
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(row >=0 && row < rows && col >=0 && col < cols && grid[row][col] == '0') return;
        // We do not move forward if we have already found a 0. We simply return.
        // We check for 4 neighbors only if we find a 1.
        
        grid[row][col] = '0';
        
        if(row-1 >=0 && grid[row-1][col] == '1') dfs(row-1, col, grid);
        if(row+1 <rows && grid[row+1][col] == '1') dfs(row+1, col, grid);
        if(col-1 >=0 && grid[row][col-1] == '1') dfs(row, col-1, grid);
        if(col+1 <cols && grid[row][col+1] == '1') dfs(row, col+1, grid);
        
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        
        /*
        
        1. Simple DFS Solution
        2. If you find 1:
            i. increase islands
            ii. Visit all neighbors, and mark them as visited
        
        
        
        */
        int islands = 0;
                
        for(int i = 0; i < grid.size(); i++){
            
            for(int j = 0; j < grid[0].size(); j++){
                
                if(grid[i][j] == '1') {
                    
                    islands++;
                    dfs(i, j, grid);
                    
                }
                
            }
        }
        
        return islands;
    }
};