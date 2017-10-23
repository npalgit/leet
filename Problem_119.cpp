// Problem 119

using namespace std;

typedef vector<int> Vector;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        
        Vector answer(rowIndex +1, 1);
        
        if(rowIndex == 0 || rowIndex == 1) return answer;
        
        long comb = 1;
        
        int i = 1;
        for (int j = rowIndex; j >= rowIndex/2 ; j--){
            
            comb *= j;
            comb /= i;
            i++;
            
            answer[j-1] = (int)comb;
            answer[i-1] = (int)comb;
        
            
        }
        return answer;
    }
};