// Problem 378


using namespace std;

typedef vector<int> Vector;
typedef pair<int, int> Pair;
typedef pair<int, Pair> DoublePair;

typedef vector<Vector> Matrix;
typedef priority_queue<DoublePair, vector<DoublePair>, greater<DoublePair>> PQ;



class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        /*
        1. It is the same problem as the one before.
        2. Only change is that it requires a priority Queue built on the element, and not on the sum
        3. Corner Cases are still the same
        4. But, continue condition is changed from rows to cols.
        
        
        */
        
        PQ myPQ;
        int rows = matrix.size();
        
        int cols = matrix[0].size();
        
        
        
        if(k > rows * cols) k = rows * cols;
        
        for(int i = 0; i < rows; i++){
            
            myPQ.push(make_pair(matrix[i][0],  make_pair(i,0) ));
            
        }
        
        
        int totalPops = k;
        int elem;
        
        while(totalPops){
            
        
            DoublePair dPair = myPQ.top();
            
            elem = dPair.first;
            
            int row = dPair.second.first;
            int col = dPair.second.second;
            
            
            myPQ.pop();
             
             
            if(col >= cols) continue;
            
           
            
            col++;
            int nextElement = matrix[row][col]; 
            
            myPQ.push( make_pair(nextElement,  make_pair(row, col)));
            
            totalPops--;
            
            
            
        }
        
        
        return elem;
        
        
        
        
        
    }
};