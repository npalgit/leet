// Problem 358


using namespace std;

typedef pair<int, char> Pair;
typedef pair<int, int> IntPair;
typedef unordered_map<char, int> HashMap;
typedef priority_queue<Pair, vector<Pair>, less<Pair>> PQ;

class Solution {
public:


    string rearrangeString(string str, int k) {
    
        if(k == 0) return str;
    
        int length = str.size(); 
        
        string result;
        HashMap myMap;
        PQ myPQ;
        
        for(char ch : str) myMap[ch]++;
        
        for(auto x : myMap){
            myPQ.push({x.second, x.first});
        }
        
        while(myPQ.size()){
            
            // Used to build the cache everytime again and again
            vector<pair<int, char>> cache;
            
            
            // length actually stores the number of remaining characters to be filled in string
            // count actually stores the number of steps to take while filling chars
            int count = min(k, length); 
            
            
            for(int i = 0; i < count; i++){
            
    
                // if PQ gets empty, that means uniques characters exhausted
                // but count > 0, which means we still need to fill chars
                // Hence, no solution possible
                if(myPQ.empty()) return "";
    
                            
                auto tmp = myPQ.top();
                myPQ.pop();
                
                result.push_back(tmp.second);
                
                // If non-zero even after pushing in result, put in cache to later push in PQ
                if(--tmp.first > 0) cache.push_back(tmp);
                
                length--;
            }
            
            // Everytime we build the priority Queue, it will contain only unique charcters based on their count
            for(auto p : cache) myPQ.push(p);
        }
        
        return result;
    }
    
    
    
    
};