// Problem 406


using namespace std;

typedef pair<int, int> Pair;
typedef vector<Pair> Vector;
typedef Vector::iterator VectorItr;
typedef priority_queue< Pair, Vector> MAX_PQ;

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
            
            /*
            1. Very good Question
            2. Requires some thinking and visualization.
            3. Uses the trick that Priority Q in C++ sorts on both elements
            4. Solved in HEAPS section
            
            
            
            */
            
            Vector result;
            if(people.size() == 0) return result;
            
          
            MAX_PQ bigPQ;
            
            // Construct a Max Priority Queue to return maximum heights
            for(auto x : people) bigPQ.push({x.first, x.second}); 
            
            
            
            VectorItr itr;
            
            // Create a Temporary Vector
            Vector temp;
            
            while(bigPQ.size() != 0){
                
                
                int topElem = bigPQ.top().first;
            
                // Loop until the first element in MAX PQ equals the first of extracted elements
                // Build a temp Vector like this
                while(bigPQ.size() != 0 && bigPQ.top().first == topElem){
                
                    temp.insert(temp.begin(), bigPQ.top());
                    bigPQ.pop();
                
                    
                }
                
                // Keep on doing this until temp vector is not empty
                while(temp.size() != 0){
                    
                    itr = result.begin();
                    
                    int index =  temp.front().second;
                    
                    advance(itr, index);
                    
                    result.insert(itr, temp.front());
                    
                    temp.erase(temp.begin());
                    
                }
                
            }
            
            
            
            return result;
            
        
    }
};