// Problem 150

using namespace std;

typedef stack<string> Stack;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        /*
        
        1. The solution uses Stack.
        2. Easy trick is to how to check if a string is an integer or not.
        3. Use a try catch block. See how to catch all types of exceptions
        4. Not Solved anywhere.
        
        */
        
        if(tokens.empty()) return 0;
        Stack myStack;
        string curr;
        
        for(int i = 0; i < tokens.size(); i++){
            
            curr = tokens[i];
            
            
            try{
                
                int currInt = stoi(curr);
                myStack.push(curr);
            }
            
            catch(...){
                
                int elem1 = stoi(myStack.top());
                myStack.pop();
                
                int elem2 = stoi(myStack.top());
                myStack.pop();
                
                int result;
                if(curr == "+") result = elem1  + elem2;
                else if(curr == "-") result = elem2 - elem1;
                else if(curr == "*") result = elem1 * elem2;
                else if(curr == "/") result = elem2/elem1;
                
                
                string resultStr = to_string(result);
                
                
                myStack.push(resultStr);
                
                
            }
            
        }
            string finalResult = myStack.top();
            myStack.pop();
            
            return stoi(finalResult);
            
        
                
        
    }
};