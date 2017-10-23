// Problem 394

using namespace std;

typedef stack<string> Stack;

class Solution {
public:
    string decodeString(string s) {
        
        /*
        1. This is not a simple Problem
        2. It mainly deals with Corner Cases and use of language
        3. One thing to look here is how char and string are converted into each other in C++.
        
        */

        string result;
        //if(s.empty()) return result;
        
        string openBrace = "[";
        string closeBrace = "]";
        
        Stack myStack;
        
        for(int i = 0; i < s.size(); i++){
            
            
            string chString(1, s[i]);
            
            //cout << "String  =  "  << chString << endl;
            
            if(chString != closeBrace) myStack.push(chString);
            else{
                
                
                string currString = "";
                while(myStack.top() != openBrace){
                    
                    currString = myStack.top() + currString;
                    myStack.pop();
                }
                
                myStack.pop();
                
                string repeatStr = "";
                while(1 && myStack.size()){
                    
                    string topString = myStack.top();
                    char ch  = topString[0];
                    //cout << "Top Char  = " << ch << endl;
                    if(isdigit(ch)){
                        
                        repeatStr = topString + repeatStr;
                        myStack.pop();
                        
                    }
                    
                    else break;
                    
                }
                
                int repeat = stoi(repeatStr);
                //cout << "Repeat  = " << repeat << endl;
                
                //cout << "Current String = " << currString << endl;
                
                string pushString = "";
                while(repeat){
                    
                    pushString = pushString + currString;
                    repeat--;
                }
                
                //cout << "Push String = " << pushString << endl;
                myStack.push(pushString);
                
                
            }
            
            
        }
        
        while(myStack.size()){
            
            result = myStack.top() + result;
            myStack.pop();
            
        }
        
        return result;
        
    }
};