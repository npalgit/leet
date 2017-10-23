// Problem 13

using namespace std;

typedef unordered_map<string, int> HashMap;

class Solution {
private:
    HashMap myMap;
    
public:

    Solution() {
        
        myMap["I"] = 1; 
        myMap["IV"] = 4;
        myMap["V"] = 5; 
        myMap["IX"] = 9;
        
        myMap["X"] = 10; 
        myMap["XL"] = 40;
        myMap["L"] = 50; 
        myMap["XC"] = 90;
        
        myMap["C"] = 100; 
        myMap["CD"] = 400;
        myMap["D"] = 500; 
        myMap["CM"] = 900;
            
        myMap["M"] = 1000; 
        
        
    }
    int romanToInt(string s) {
        
        int answer = 0;
        while(s.size()) {
            
            string temp = s.substr(0,2);
            if(myMap.find(temp) != myMap.end()){
                
                answer = answer + myMap[temp];
                s.erase(0,2);
                
            }
            else {
                
                temp = s.substr(0,1);
                answer = answer + myMap[temp];
                s.erase(0,1);
                
            }
            
            
            
        }
        
        return answer;
        
    }
};