// Problem 22

using namespace std;

typedef vector<string> Vector;

class Solution {
public:
    
    string openB = "(";
    string closeB = ")";
    
    void giveResult(Vector & result, string partial, int pairs, int open){
    
        if(open < 0 || open > pairs) return;
        
        if(open ==0 && pairs == 0){
            result.push_back(partial);
            return;   
        }
        
        // Open Brace Case
        partial = partial + openB;
        giveResult(result, partial, pairs, open+1);
        
        //Closing Brace Case
        partial.erase(partial.size()-1, 1);
        partial = partial + closeB;
        giveResult(result, partial, pairs-1, open-1);
        
    }
    
    vector<string> generateParenthesis(int n) {

                
      
        string str = "";
        
        Vector result;
        
        giveResult(result, str, n, 0);
        
        return result;
        
    }
};
