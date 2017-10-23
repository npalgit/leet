// Problem 43

using namespace std;

typedef vector<int> Vector;
class Solution {
public:
    string multiply(string num1, string num2) {
        
        
        /*
        1. This problem is very easy after reversing the initial string.
        2. Corner Cases are important. Explained in a detailed manner in the notes.
        3. Solved in Strings.
        
        */
        
        if(num1 == "0" || num2 == "0") return "0";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        
        Vector prod(num1.size() + num2.size() + 2, 0);
        
        int value1, value2, ans, value, carry, rem, i, j;
        
        for(i = 0; i < num1.size(); i++){
            
            carry = 0;
            for(j = 0; j < num2.size(); j++){
                
                value1 = num1[i] - '0';
                value2 = num2[j] - '0';
                
                
                ans = value1 * value2;
                
                value = ans + carry + prod[i+j];
                
                rem = value%10;
                carry = value/10;
                
                prod[i+j] = rem;
                
                
                
            }
            
            prod[i+j] = carry;
            
            
        }
        

        reverse(prod.begin(), prod.end());
        
       
        while(prod[0] == 0){
            
            prod.erase(prod.begin());
        }
        
 
        string result = "";
        

        for(auto x : prod) result = result  + to_string(x);

        if(result.empty()) result = "0";
        
        return result;
    }
};