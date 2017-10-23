// Problem 387


using namespace std;

typedef pair<int, int> Pair;
typedef unordered_map<char, Pair> HashMap;


class Solution {
public:
    int firstUniqChar(string s) {
        
        /*
            1. Simple Hash Map Implementation
            2. Return Minimum Index of all the elements that occur only once.
            
        */
        
        HashMap myMap;
        
        for(int i = 0; i < s.size(); i++){
            
            if(myMap.find(s[i]) == myMap.end()){
                
                myMap[s[i]] = make_pair(1, i);
            }
            
            else{
                
                int count = myMap[s[i]].first;
                myMap.erase(s[i]);
                myMap[s[i]] = make_pair(count+1, i);
            }
        }
        
        int minIndex = INT_MAX;
        for(auto x : myMap){
            
            //cout << x.first <<" : " << x.second.first << " : " << x.second.second << endl;
            
            if(x.second.first == 1) minIndex = min(minIndex, x.second.second);
        }
        
        
        return minIndex == INT_MAX ? -1 : minIndex ;
    }
};