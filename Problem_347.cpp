// Problem 347


using namespace std;

typedef pair<int, int> Pair;
typedef unordered_map<int, int> Map;
typedef vector<Pair> Vector;
typedef vector<int> IntVector;

typedef priority_queue<Pair, Vector, greater<Pair>> PQ;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        /*
        1. Definitely do this problem for Syntax using the Heaps
        2. Also see why we are using a Min Heap over here.
        3. Done in HEAPS section
        4. Simple problem though
        
        */
        
        IntVector myVect;
        PQ myPQ;
        Map myMap;
        
        Pair myPair;
        
        for(auto num: nums) myMap[num]++;
        
        for(auto ptr: myMap) {
            
            //myPair = *ptr;
            
            myPQ.push({ptr.second, ptr.first});
            
            
            
        }
        
        while(myPQ.size() > k) myPQ.pop();
        
        while(myPQ.empty() != 1){
            
            myPair = myPQ.top();
            myVect.push_back(myPair.second);
            myPQ.pop();
        }
        
        return myVect;
    }
};