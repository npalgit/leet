// Problem 241

using namespace std;

typedef vector<int> Vector;
typedef unordered_map<string, Vector> HashMap;
typedef HashMap::iterator HashItr;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        
        /*
        
        1. Returns the final answer in vector format
        2. Idea is to break the string at each operator, and then see which 2 substrings form
        3. If substring exists in map,  take its vector and evaluate it.
        4. Repeat this procedure
        
        */
        
        
        Vector ans;
        HashMap myMap;
        
        Vector finalAns  = computeAns(input, myMap);
        
        return finalAns;
    }
    
    
    
    Vector computeAns(string input, HashMap & myMap){
        
        
        HashItr itr = myMap.find(input);
        
        if(itr != myMap.end()){
            
            return myMap[input];
        }
        
        Vector ans;
        
        int pureNum = 1;
        
        for (int i = 0; i < input.length(); i++) {
            
        
            if (isdigit(input[i]) == 0) {
                
                pureNum = 0;
                
                Vector  L = computeAns(input.substr(0, i), myMap);
                Vector  R = computeAns(input.substr(i+1, input.length()-i-1), myMap);
                
                for (auto l : L){
                                    
                    for (auto r : R){
                                            
                        if (input[i] == '+') ans.push_back(l+r);
                        else if (input[i] == '-') ans.push_back(l-r);
                        else if (input[i] == '*') ans.push_back(l*r);
                        
                    }
            
                }
            
            }       
            
        }
        
        
        if (pureNum) ans.push_back(atoi(input.c_str()));
        return ans;
        
        
    }
    
    
    
};