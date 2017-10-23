// Problem 386


using namespace std;

typedef vector<int> Vector;


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        Vector answer;
        
        int curr = 1;
        for (int i = 1; i <= n; i++) {
            
            answer.push_back(curr);
            
            // Case 1: Multiply by 10
            if (curr * 10 <= n) {
                curr = curr * 10;
            } 
            
            // Case 2: Add 1
            else if (curr % 10 != 9 && curr + 1 <= n) {
                curr++;
            } 
            
            
            // Case 3: Divide by 10 and add 1
            else {
                
                
                // Specific Corner Case of ending with 9
                while ((curr / 10) % 10 == 9) {
                    curr = curr / 10;
                }
                
                curr = (curr / 10) + 1;
            }
        }
        
        return answer;
        
    }
};