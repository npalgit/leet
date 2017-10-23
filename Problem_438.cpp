// Problem 438

using namespace std;

typedef unordered_map<char, int> HashMap;
typedef vector<int> Vector;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        /*
        
        1. Easy Problem
        2. Corner Cases are important here.
        3. Better to do it with a Vector Map than a Hash Map
        4. You can use relational operators on Vectors and HashMaps as well.
        
        */
        
        Vector answer;
        if(s.empty() || p.empty()) return answer;
        if(s.size() < p.size()) return answer;
        
        HashMap pMap;
        for(auto x :p){
            
            pMap[x]++;
        }
        
        
        HashMap sMap;
        int pSize = p.size();
        
        string start = s.substr(0, pSize);
        for(auto x : start){
            
            sMap[x]++;
        }
        
        for(int i = 0; i < s.size() - pSize+1; i++){
            
            if(sMap == pMap) answer.push_back(i);
            
            sMap[s[i]]--;
            if(sMap[s[i]] == 0) sMap.erase(s[i]);
            sMap[s[i+pSize]]++;
            
            
            
            
        }
            
        return answer;      
    }
};