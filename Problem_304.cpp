// Problem 304


using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class NumMatrix {
private:
    Matrix table;
    Matrix copyMatrix;
    
public:
    
    void printTable(Matrix & table) {
        
        for(auto x : table){
            
            for(auto y : x){
                
                cout << y << " : ";
                
            }
            
            cout << endl;
        }
        
        cout << endl << endl;
        
    }
    NumMatrix(vector<vector<int>> matrix) {
        
        if(matrix.empty()) return;
        if(matrix[0].empty()) return;
        
        copyMatrix = matrix;
        table = matrix;
        
       // printTable(table);
        
        for(int j = 0; j < table[0].size(); j++){
            
            for(int i = 1; i < table.size(); i++) {
                
                table[i][j] = table[i-1][j] + matrix[i][j];
                
                
            }
            
            
        }
        
        //printTable(table);
        
        
        for(int i = 0; i < table.size(); i++){
            
            for(int j = 1; j < table[0].size(); j++) {
                
                table[i][j] = table[i][j-1] + table[i][j];
                
                
            }
            
            
        }
        
        
      //printTable(table);
        
    }
    
    void update(int row, int col, int val) {
        
        int delta = val - copyMatrix[row][col];
        
        for(int i = row; i < table.size(); i++){
            
            
            for(int j = col; j < table[0].size(); j++){
                
                table[i][j] = table[i][j] + delta;
                
            }
        }
        
        
        
        
        copyMatrix[row][col] = val;
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        
        int add = table[row2][col2];
        if(row1 > 0 && col1 > 0) add = add + table[row1-1][col1-1];
        
        int sub = 0;
        if(row1 > 0) sub = sub + table[row1-1][col2];
        if(col1 > 0) sub = sub + table[row2][col1-1];
        
        int result = add - sub;
        
        return result;
        
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */