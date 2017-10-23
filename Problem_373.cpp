// Problem 373



using namespace std;

typedef vector<int> IntVector;
typedef pair<int, int> Pair;
typedef pair<int, Pair> DoublePair;

typedef vector<DoublePair> Vector;
typedef priority_queue<DoublePair, Vector, greater<DoublePair>> PQ;
typedef vector<Pair> PairVector;


class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        /*
        1. Very good question to practice C++ Syntax of Priority Queue
        2. Corner Cases are important here
        3. Follow the logic and take care of corner cases
        4. Solved in HEAPS section.
        
        
        */
        
        
        PairVector sPair;
        PQ myPQ;
        
        PairVector ans;
        
        // 2 Corner Cases
        if(nums1.empty() || nums2.empty()) return ans;
        if(k > nums1.size() * nums2.size()) k = nums1.size() * nums2.size();
        
        
        for(int i = 0; i < nums2.size(); i++){
                
            Pair myPair(0, i);
            DoublePair dPair(nums1[0] + nums2[i], myPair);
            myPQ.push(dPair);
            
        }
        
        
        
        while(ans.size() != k){
            
            // Fetching the Top element of the Priority Queue and putting it in the answer vector
            DoublePair otherPair = myPQ.top();
            
            int firstIndex = otherPair.second.first;
            int secondIndex = otherPair.second.second;
            
            Pair ansPair(nums1[firstIndex], nums2[secondIndex]);
            ans.push_back(ansPair);
            
            
            // Incrementing the first index only after pushing the answer in the answer vector
            firstIndex++;
            
            
            // Releasing the element that was put inside the answer vector
            myPQ.pop();
            
            
            
            // Corner Case
            if(firstIndex > nums1.size()-1) continue;
            
            
            // Pushing the next Pair into the Priority Queue
            Pair inSPair(firstIndex, secondIndex);
            DoublePair inDPair(nums1[firstIndex] + nums2[secondIndex], inSPair);
            
            myPQ.push(inDPair);
            
            
        }
        
        return ans;
        
    }
};