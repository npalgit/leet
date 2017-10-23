// Problem 120

using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;
typedef Vector::iterator VectorItr;

class Solution {
public:
    
 
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        
        Vector minSum = triangle.back();
        
        for(int row = triangle.size()-2; row>=0; row--){
            
            
            for(int i =0; i < triangle[row].size(); i++){
                
                
                minSum[i] = min(minSum[i], minSum[i+1]) + triangle[row][i];
            }
            
            
        }
        
        return minSum[0];
    }
};