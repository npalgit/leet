// Problem 76

using namespace std;

typedef unordered_map<char, int> HashMap;

class Solution {
public:

    void printMap(HashMap & myMap){
        
        for(auto x : myMap){
            
            cout << x.first << " : " << x.second <<  endl;
        }
        
        cout << endl;
        
    }
    string minWindow(string s, string t) {


        string answer;
        string candidate;
        
        HashMap myMap;
        
        for(auto x : t){
            
            myMap[x]++;
        }
        
        //printMap(myMap);
        
        int left = 0; int right = 0;
        int counter = 0;
        
        while( right < s.size()){
            
            
                // Associativity is from Right to Left
                if(myMap[s[right++]]-- > 0) {
                    counter++;
                    
                    
                }
                
           
            
           
            
            //cout << "Counter = " << counter << endl;
            while(counter == t.size()){
                
                candidate = s.substr(left, right - left);
                
                //cout << "Candidate = " << candidate << endl;
                
                if(answer.empty())answer = candidate;
                else{
                    
                    if(answer.size() > candidate.size()) answer = candidate;
                    
                }
                
                if(myMap[s[left++]]++ == 0){
                   
                  counter--;
                  
                }
                
            }
            
        }
        
        
        
        
        
        return answer;
        
    }
};