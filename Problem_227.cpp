// Problem 227

class Solution {
public:
    int calculate(string s) {
       stack<char> opS;
       stack<int>  numS;
       s.push_back(')'); // to make sure the last operand will be saved in the stack e.g. 1+2*3), 2*3 will be calculated and push in the stack
       opS.push('+'); // sign for the first operand
       
       int i, curNum, len = s.size(), res =0;
       for(i=0,curNum=0; i<len; ++i)
       {
           if(isdigit(s[i])) curNum = curNum*10 + s[i] -'0'; // digit, recover the oprand
           else if(isspace(s[i])) continue; // skip the space
           else
           {
               switch(opS.top())
               { 
                   case '*': // if the last operator is * / , do calculation
                   case '/':
                        curNum = opS.top()=='/'?numS.top()/curNum : numS.top()*curNum;
                        opS.pop();
                        numS.pop();
               }
                numS.push(curNum); 
                curNum = 0;
                opS.push(s[i]);
           }
       }
       opS.pop(); // skip the ")"
       while(!opS.empty()) {res += (opS.top()=='-')? -numS.top(): numS.top(); opS.pop(); numS.pop();}
       return res;
    }
};