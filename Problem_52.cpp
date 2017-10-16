// Problem 52

using namespace std;

typedef vector<string> Vector;
typedef vector<Vector> Matrix;
typedef vector<int> IntVector;

class Solution {
public:


        int checkValidity(IntVector & dp, int row, int col){
        
        for(int i = 0; i < row; i++){
            
            //if((dp[i] == col) || (abs(row  - i) == abs(dp[i] - col))){
            if((dp[i] == col) || ((row  - col) == (i - dp[i])) || (dp[i] + i == row + col)){
                
                return 0;
            }
            
        }
        
        return 1;
        
    }
    
    void helpQueens(Matrix & answer, Vector & solution, IntVector & dp, int row, int n){
    
        if(row == n){
            
            answer.push_back(solution);
            return;
            
        }    
        
        
        for(int col = 0; col < n; col++){
            
            if(checkValidity(dp, row, col)){
                
                dp[row] = col;
                solution[row][col] = 'Q';
                helpQueens(answer, solution, dp, row+1, n);
                solution[row][col] = '.';
                
            }
            
            
        }
        
        return;
        
        
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        /*
        1. This is a simple backtracking problem. The trick mainly lies on how to write it.
        
        */

        Matrix answer;
        string blankString(n, '.');
        Vector solution(n, blankString);
        IntVector dp(n);
        
        //cout << "I am here " << endl;
        helpQueens(answer, solution, dp, 0, n);
        
        
        return answer;
    }
    
    int totalNQueens(int n) {
        
        Matrix answer = solveNQueens(n);
        return answer.size();
        
    }
};