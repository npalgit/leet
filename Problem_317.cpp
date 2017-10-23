// Problem 317


using namespace std;


typedef pair<int, int> Pair;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;
typedef vector<Pair> VectorPair;
typedef queue<Pair> Queue;

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        
        
        
        int totalRows = grid.size();
        if(totalRows == 0) return -1;
        
        int totalCols = grid[0].size();
        if(totalCols == 0) return -1;
        
        Matrix total = grid;
        int walk = 0;
        int minDist;
        
        VectorPair dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        
        for (int i = 0; i < totalRows; i++) {

            for (int j = 0; j < totalCols; j++) {
                
                // 1 denotes a building
                if (grid[i][j] == 1) {
                    
                   
                    minDist = INT_MAX;
                    
                    // This matrix is re-filled for every building present
                    Matrix dist = grid;
                    
                    Queue myQ;
                    myQ.push({i,j});
                    
                    
                    while (myQ.size()) {
                        
                        
                        int row = myQ.front().first;
                        int col = myQ.front().second;
                        
                        myQ.pop();
                        
                        
                        for (auto dir : dirs) {
                            
                            
                            int x = row + dir.first;
                            int y = col + dir.second;
                            
                            // Out of Bonds Terminating Condition
                            if (x < 0 || x >= totalRows || y < 0 || y >= totalCols) continue;
                            
                            // Extra Condition for Termination
                            if(grid[x][y] != walk) continue;
                            
                                
                                //-----------------------------------------
                                // Post Processing Starts
                                
                                // (x,y) location has been visited by 1 more building
                                grid[x][y]--;
                                
                                // Stores distance of (x,y) from current building
                                dist[x][y] = dist[row][col] + 1;
                                
                                // Stores total distance of (x,y) from all buildings seen till then
                                total[x][y] = total[x][y] + dist[x][y] - 1;
                                
                                // Stores minimum Possible Distance
                                minDist = min(minDist, total[x][y]);
                                
                                
                                // Post Processing Ends
                                // -----------------------------------------
                                
                                myQ.push({x,y});
                            
                        }
                        
                        
                    }
                    
                    // If walk is -2, it tells that we have visited 2 buildings till now
                    // We cannot use Positive values for this as 0,1,2 have been used up
                    walk--;
                    
                }
            }
        }
        
        if(minDist == INT_MAX) return -1;
        return minDist;
        
        
        
    }
};