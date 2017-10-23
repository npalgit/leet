// Problem 244

using namespace std;

typedef vector<string> Vector;
typedef vector<int> IntVector;
typedef unordered_map<string, IntVector> HashMap;


class WordDistance {

private:

    HashMap myMap;
    
    
public:
    WordDistance(vector<string>& words) {
        
        IntVector myVect;
        for(int  i = 0; i < words.size(); i++){
            
            if(myMap.find(words[i]) == myMap.end()){
                
                
                myVect.push_back(i);
                myMap[words[i]] = myVect;
                myVect.clear();
                
            }
            
            else{
                
                
                IntVector orgVect = myMap[words[i]];
                orgVect.push_back(i);
                myMap[words[i]] = orgVect;
                
            }
            
            
            
        }
        
    }

    int shortest(string word1, string word2) {
        
        int minDist = INT_MAX;
        
        IntVector vect_1 = myMap[word1];
        IntVector vect_2 = myMap[word2];
        
        int i = 0, j = 0;
        
        // Only 1 loop required to calculate the minimum distance between every possible set of 
        // elements in 2 arrays if both the arrays are sorted
        
        while( i < vect_1.size() && j < vect_2.size() ){
            
            minDist = min(minDist, abs(vect_1[i] - vect_2[j]));
            
            if(vect_1[i] < vect_2[j])i++;
            else j++;
            
        }
        
        return minDist;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");