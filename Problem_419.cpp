// Problem 419


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        /*
        1. Very simple logic
        2. Traverse the board once
        3. Self Explanatory Code
        4. 
        
        
        */
        
        if(board.size()==0) return 0;
        
        int rows = board.size();
        int cols = board[0].size();
        
        //cout << "Rows = " << rows <<": Cols = " << cols << endl;
        int count  = 0;
        
        for(int i = 0; i < rows; i++){
            
            for(int j = 0; j < cols; j++){
                
                
                if(board[i][j] == '.') continue;
                if(i > 0 && board[i-1][j] == 'X') continue;
                if(j > 0 && board[i][j-1] == 'X') continue;
                
                count++;
                
            }
        }
        
        return count;
        
    }
};