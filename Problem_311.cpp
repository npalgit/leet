// Problem 311


using namespace std;

typedef pair<int, int> Pair;
typedef vector<Pair> Vector;
typedef vector<Vector> Matrix;

typedef vector<int> IntVector;
typedef vector<IntVector> IntMatrix;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        
        /*
        
        1. VERY important Question
        2. Most Important thing is to visualize why the 3 loops are organized in the particular fashion
        
        */
        
        Matrix sparse;
        Vector temp;
        
        
        // 1. Building the Sparse Matrix from the given B Matrix
        
        for(int i = 0; i < A.size(); i++){
            
            temp.clear();
            for(int j = 0; j < A[0].size(); j++){
                
                if(A[i][j] != 0){
                    
                    temp.push_back({j, A[i][j]});
                } 
            }
            
            sparse.push_back(temp);
        }
        
        /*
        for(auto x: sparse){
            
            for(auto y  : x){
                
                cout << y.first << " : " << y.second << " ** ";
            }
            
            cout << endl;
        }
        
        */
        
        int finalRows = A.size();
        int finalCols = B[0].size();
        
        
        //cout << "Final Rows = " << finalRows << ": Final Cols = " << ": sRows = " << sRows << endl; 
        
        
        // 2. Building the Final Result Vector
        
        IntMatrix result;
        IntVector partial(B[0].size(), 0);
        
        int countRows = 0;
        while(countRows < finalRows){
            
            result.push_back(partial);
            countRows++;
        }
        
        
        //cout << "Sparse Size = " << sparse.size() << endl;
        //cout << "Temp Size = " << temp.size() << endl;
        
        
        // 3. Iterate the Final Result Vector
        
        // i will be the final row in the result vector
        for(int i = 0; i < finalRows; i++){
            
            // temp is that specific row of the sparse matrix
            Vector temp = sparse[i];
            
            // k will be the number of non-zero elements in that row of the sparse matrix
            for(int k = 0; k < temp.size(); k++){
                
                int row = temp[k].first;
                int value = temp[k].second;
                
                //cout << "Col = " << col << " : Value = " << value << endl;
                
                
                // j will be the final column in the result vector
                for(int j = 0; j < finalCols; j++){
                    
                    result[i][j] = result[i][j] +  B[row][j] * value;
                    
                }
                
            }
        }
        
        
        return result;
    }
};