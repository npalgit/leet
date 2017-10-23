// Problem 221


#include<algorithm>
using namespace std;

typedef vector<char> Vector;
typedef vector<Vector> Matrix;


class Solution {
public:

    void printTable(Matrix & table) {
        
        for(int i = 0; i < table.size(); i++){
            
            
            for(int j = 0; j < table[0].size(); j++){
                
                cout << table[i][j] << " : ";
                
                
            }
            
            cout << endl;
        }
        
        
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.empty()) return 0;
        
       // cout << "Original Matrix  = " << endl;
        //printTable(matrix);
        int matrixRows = matrix[0].size();
        
        Vector row(matrixRows+1, '0');
       
        matrix.insert(matrix.begin(), row);
        
        for(int i = 0; i < matrix.size(); i++){
         
            matrix[i].insert(matrix[i].begin(), '0');   
        }
        
        cout << endl << endl;
        //printTable(matrix);
        //cout << "Matrix Size = " << matrix.size() << " " << matrix[0].size() << endl; 
        
        
        
        
        
        
        
        char value;
        for(int i = 1; i < matrix.size(); i++){
            
            Vector row2(matrix[0].size(), '0');
            
            for(int j = 1; j < matrix[0].size(); j++){
                
                if(matrix[i][j] == '0')continue;
                
                if(matrix[i][j] == '1'){
                    
                    int value1 = matrix[i-1][j-1] - '0';
                    int value2 = matrix[i-1][j] - '0';
                    
                    int value3 = row2[j-1] - '0';
                    //cout << "Value 1 = " <<value1 << "  Value 2 = " <<value2 << "  Value 3 = " << value3 << endl;
                    value = min(min(value1, value2), value3);
                    value = value + 1;
                    //cout << "Value = " << value << endl;
                    
                    char ch = value + '0';
                    row2[j] = ch;
                    
                }
                
               
               // cout << endl;
            }
            
            //cout << "Inserted Row = " << endl;
            //for(auto x: row2) cout << x << " : " ;
            //cout << endl;
            
            matrix.insert(matrix.begin()+i, row2);
            
            //cout << endl << endl;
            matrix.erase(matrix.begin() +i +1);
            
            
            //printTable(matrix);
            row2.clear();
        }
        
        //printTable(matrix);
        
         int maxValue = INT_MIN;
        for(int i = 0;i < matrix.size(); i++){
            
            for(int j= 0; j< matrix[0].size(); j++){
                
                if(maxValue < (matrix[i][j] - '0'))  maxValue = matrix[i][j] - '0';
                
            }
        }
        
        
        return maxValue*maxValue;
    }
};