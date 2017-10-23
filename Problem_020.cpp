//Problem 20

using namespace std;


typedef vector<char> Vector;
typedef unordered_map<char, int> HashMap;
typedef stack<char> Stack;

class Solution {
public:
    bool isValid(string s) {
        
        
        
        Stack myStack;
        
        
        
        
        for(int i = 0; i < s.size(); i++){
            
         
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') myStack.push(s[i]);
            else if(s[i] == ')'){
                
                if(myStack.size() && myStack.top() == '('){
                    
                    myStack.pop();
                }
                
                else return false;
            }
            
            else if(s[i] == '}'){
                
                if(myStack.size() &&  myStack.top() == '{'){
                    
                    myStack.pop();
                }
                
                else return false;
            }
            
            else if(s[i] == ']'){
                
                if(myStack.size() &&  myStack.top() == '['){
                    
                    myStack.pop();
                }
                
                else return false;
            }
            
            
        }
        
        if(myStack.empty()) return true;
        else return false;
        
    }
};