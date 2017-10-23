// Problem 423

using namespace std;

typedef vector<int> Vector;

class Solution {
public:

    
    string originalDigits(string s) {
        
        /*
        1. Simple Problem
        2. This is mainly an observation problem.
        
        
        */


        Vector count(10,0);
        
        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == 'z') count[0]++;
            if(s[i] == 'w') count[2]++;
            if(s[i] == 'u') count[4]++;
            if(s[i] == 'g') count[8]++;
            if(s[i] == 'x') count[6]++;
            
            if(s[i] == 's') count[7]++; // 6,7
            if(s[i] == 'h') count[3]++; // 3,8
            
            if(s[i] == 'v') count[5]++; // 5,7
            if(s[i] == 'o') count[1]++; // 0,1,2,4
            
            if(s[i] == 'i') count[9]++; // 5,6,8,9
            
        }
        
        count[7] = count[7] - count[6];
        count[3] = count[3] - count[8];
        count[5] = count[5] - count[7];
        
        count[1] = count[1] - count[0] - count[2] - count[4];
        count[9] = count[9] - count[5] - count[6] - count[8];
        
        
        //printVector(count);
        
        string result;
        
        for(int j = 0; j < 10; j++){
            
            while(count[j]) {
                
                result = result + to_string(j); 
                count[j]--;
                
            }
        }
        
        return result;
        
    }
};