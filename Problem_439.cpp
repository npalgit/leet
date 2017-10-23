// Problem 439


using namespace std;

typedef stack<char> Stack;

class Solution {
public:
    string parseTernary(string expression) {
        
        
        /*
        
        1. Solved using Stack
        2. Main Key to notice is that because of demand of the problem, we have to build 
            stack from the string while going backwards from the string
        3.  
        
        */
    
        Stack myStack;
        
        for(int i = expression.size(); i >= 0; i--){
            
            char currChar = expression[i];
            
            // Pushing until we encounter the '?'
            if(currChar != '?') myStack.push(currChar);
            
            // Build cases in case we encounter a '?'
            else{
                
                char trueCase = myStack.top();
                
                myStack.pop();
                myStack.pop();
                
                char falseCase = myStack.top();
                myStack.pop();
                
                i--;
                
                char boolChar = expression[i];
                
                if(boolChar == 'T') myStack.push(trueCase);
                if(boolChar == 'F') myStack.push(falseCase);
                
            }
            
            
        }
        char ans = '@';
        if(myStack.size() > 0) ans = myStack.top();
        
        //cout << "Ans = " << ans << endl; 
        //cout << "Is Digit = " << isdigit(ans) << endl;
        
        
        
        // Building the Final Answer in the String Format
        string finalAns;
        
        if(isdigit(ans)) finalAns = to_string(ans - '0');
        else finalAns = finalAns + ans;
        
        return finalAns;
        
    }
};