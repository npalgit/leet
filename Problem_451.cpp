// Problem 451


using namespace std;

typedef unordered_map<char, int> HashMap;
typedef pair<int, char> Pair;
typedef vector<Pair> Vector;
typedef vector<int> IntVector;
typedef priority_queue<Pair, Vector, less<Pair>> PQ; 

class Solution {
public:
    string frequencySort(string s) {
        
        HashMap myMap;
        PQ myPQ;
        
        for(auto x : s){
            
            myMap[x]++;
            
        }
        
        for(auto ptr : myMap){
            
            //cout << ptr.first << " : " << ptr.second << endl;
            Pair myPair = make_pair(ptr.second, ptr.first);
            myPQ.push(myPair);
            
        }
        
       
        //cout << "Size of Map = " << myMap.size() << endl;
        //cout << "Size of Queue = " << myPQ.size() << endl;
       
        string result;
        while(myPQ.size()){
            
            Pair top = myPQ.top();
            
            char ch = top.second;
            int num = myMap[ch];
            
            //cout << "Char = " << ch << " : " << num << endl;
            string str(num, ch);
            
            //string add(str, );
            
            
            result = result + str;
            myPQ.pop();
            
        }
        
        return result;
        
        
    }
};