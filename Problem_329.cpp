// Problem 329

using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:

    int helpTravel(Matrix & table, Matrix & matrix, int i, int j, int preMax){
        
        if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) return 0;
        if(matrix[i][j] >= preMax) return 0;
        
        
        if(table[i][j]) return table[i][j];
        
        else {
            
            int currVal = matrix[i][j];
            int tempMax = 0;
            
            tempMax = max(helpTravel(table, matrix, i+1, j, currVal), tempMax);
            tempMax = max(helpTravel(table, matrix, i-1, j, currVal), tempMax);
            tempMax = max(helpTravel(table, matrix, i, j+1, currVal), tempMax);
            tempMax = max(helpTravel(table, matrix, i, j-1, currVal), tempMax);
            
            
            tempMax++;
            table[i][j] = tempMax;
            
            //cout << "TempMax in Loop = " << tempMax << endl;
            
        }
        
        
        return table[i][j];
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int answer = 0;
        
        if(matrix.size() == 0 || matrix[0].size() == 0) return answer;
        
        Vector row(matrix[0].size(), 0);
        Matrix table(matrix.size(), row);
        
        
        
        for(int i = 0; i < matrix.size(); i++){
            
            for(int j =0; j < matrix[0].size(); j++){
                
                int current = helpTravel(table, matrix, i, j, INT_MAX);
                answer = max(answer, current);
                //cout  << "Answer = " << answer << endl;
                
            }
        }
        
        
        return answer;
        
    }
};