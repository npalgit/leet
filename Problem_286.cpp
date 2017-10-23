// Problem 286

using namespace std;

typedef pair<int, int> Pair;
typedef vector<Pair> Vector;
typedef queue<Pair> Queue;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        
        int totalRows = rooms.size();
        if(totalRows == 0) return;
        
        int totalCols = rooms[0].size();
        if(totalCols == 0) return;
        
        
        Queue myQ;
        Vector dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        
        // Push all the Gates(0) into a Queue
        for(int i = 0; i < totalRows; i++){
            
            for(int j = 0; j < totalCols; j++){
                
                if(rooms[i][j] == 0) myQ.push({i, j});
                
            }
        }
        
        
        // For every location that is inside the Queue
        while(myQ.size()){
            
            int row = myQ.front().first;
            int col = myQ.front().second;
            
            // Popping the Queue is very important
            myQ.pop();
            
            // For every location in the Queue, move in all 4 directions
            for(auto dir : dirs){
                
                
                // These are the one of the 4 possible x and y starting from original location 
                int x = row + dir.first;
                int y = col + dir.second;
                
                // If out of bounds, continue
                if(x < 0  || x >= totalRows || y < 0 || y >= totalCols) continue;
                
                // If new location already knows a shorter path, continue
                if(rooms[x][y] <= rooms[row][col] + 1) continue;
                
                
                
                // ----------------------------------------
                // Post Processing Starts
                // Otherwise, this location can be reached from the original location in 1 additional step
                rooms[x][y] = rooms[row][col] + 1;
                
                // Post Processing Ends
                // ----------------------------------------
                
                // Push this location into the Queue as well, to check for its neighbors
                myQ.push({x,y});
                
                
            }
            
            
            
            
        }
        
        
        
    }
};