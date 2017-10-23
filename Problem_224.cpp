// Problem 224

using namespace std;

typedef stack<int> Stack;
//typedef stack<char> CharStack;
class Solution {
public:
    int calculate(string s) {
        
        
        /*
        
        1. Just Learn the Algorithm of this question
        2. Very hard to solve in interview at first GO.
        
        */
        
        Stack opStack;
        Stack numStack;
        
        int num = 0;
        int result = 0;
        int sign = 1;
        
        for (char ch : s) {
            
            // Everytime, we first check whether it is a Digit or Not
            // Note how we continuously build our num integer, in case continuous chars are digits
            if (isdigit(ch)) {
                
                num = num * 10 + (ch - '0');
            
            }
            
            // If the char is not a digit
            else {
                
                result = result + (sign * num);
                
                // Num is now changed to 0 as it has been stored in result above
                num = 0;
                
                if (ch == '+') sign = 1;
                else if (ch == '-') sign = -1;
                
                
                else if (ch == '(') {
                    
                    // Pushing in Stack only with Opening Brace
                    numStack.push(result);
                    opStack.push(sign);
                    
                    // Result and Sign are both reset over here
                    num = 0;
                    result = 0;
                    sign = 1;
                    
                }
                
                else if (ch == ')' && opStack.size()) {
                    
                    result = (opStack.top() * result) + numStack.top();
                    
                    // Popping in  Stack only with Closing Brace
                    opStack.pop(); 
                    numStack.pop();
                
                }
                
            }
        }
        
        result = result + (sign * num);
        
        return result;
        
        
        
    }
};