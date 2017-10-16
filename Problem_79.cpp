// Problem 79

using namespace std;

typedef vector<char> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:

    void helpFind(Matrix & board, int i, int j, string word, string pathWord, int & result) {
        
        //cout << "PathWord = " << pathWord << endl;
        
        if(result == 1) return;
        
        if(pathWord == word) { 
            result = 1;
            return;
        }
        
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        
        if(pathWord.size() > word.size()) return;
        
        int pathLen = pathWord.size();
        
        char desChar = word[pathLen];
        
        char currChar = board[i][j] ;
        
        //cout << "currChar = " << currChar << ", DesChar = " << desChar << endl;
        if(desChar != currChar) return;
        else {
            
            pathWord = pathWord + desChar;
            board[i][j] = '.';
            
            helpFind(board, i-1, j, word, pathWord, result);
            helpFind(board, i+1, j, word, pathWord, result);
            helpFind(board, i, j+1, word, pathWord, result);
            helpFind(board, i, j-1, word, pathWord, result);
            
            board[i][j] = currChar;
            
        }
            
            
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int result = 0;
        string pathWord = "";
        
        if(board.empty()) return false;
        if(board[0].empty()) return false;
        
        
        for(int i = 0; i < board.size(); i++) {
            
            for(int j = 0; j < board[0].size(); j++) {
                
                //cout << "i = " << i <<", j = "<< j << endl;
                //pathWord = "";
                helpFind(board, i, j, word, pathWord, result);
            }
            
        }
        
        
        
        
        if(result) return true;
        else return false;
        
    }
};