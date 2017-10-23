// Problem 402

using namespace std;

typedef stack<int> Stack;
class Solution {
public:
    string removeKdigits(string num, int k) {
        
        
        
        /*
        
        1. Corner Cases are important.
        2. A bit hard at first to understand that Stack will finally contain the elements to form the final number
        3. Corner Cases:
            a. See the Page for details
            b. Complicated Corner Cases
        
        */
        
        
        if(k == 0) return num;
        if(num.size() == 0) return num;
        if(k == num.size()) return "0" ;
        
        Stack myStack;
        
        for(int i = 0; i < num.size(); i++){
            
            
            while(k > 0 && myStack.empty() != 1 && myStack.top() > num[i]){
                
                myStack.pop();
                k--;
                
            }
            
            myStack.push(num[i]);
            
        }
            
        while(k){
                
            myStack.pop();
            k--;
        }
            
            
            
        string myStr = "";
            
        while(myStack.empty()!= 1){
                
            char ch = myStack.top();
            myStr = ch + myStr;
            myStack.pop();
                
                
        }
            
        //reverse(myStr.begin(), myStr.end());
            
            
        while(myStr.size() && myStr[0] == '0') myStr.erase(0,1);
            
        if(myStr.empty()) myStr = "0";
        return myStr;
            
        
        
    }
};