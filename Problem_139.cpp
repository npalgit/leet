// Problem 139

using namespace std;

typedef unordered_set<string> Set;
typedef vector<bool> Vector;

class Solution {
private:
    Set mySet;
    
public:
    
    void printVector(Vector & myVect) {
        
        
        for(auto x : myVect) {
            
            cout << x << " : ";
        }
        
        cout << endl;
        
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        
        /*
        1. Solution is O(n^2) in time and O(n) in space 
        
        
        */
        for(auto x : wordDict) mySet.insert(x);
        
        
        // Adding a dummy char to the beginning of the string
        s = "!" + s;
        Vector dpArray(s.size() );
        
        // Initializing that null word can be formed in the dictionary
        dpArray[0] = true;
        
        // i+1 signifies starting of the word
        for(int i = 0; i < s.size(); i++){
            
            // j signifies ending of the word
            for(int j = i+1; j < s.size(); j++) {
            
                // dpArray[j] = whether word starting from 0 to j can be formed
                // from the dictionary or not
                if(dpArray[j]) continue;
            
            
                // If I already know that word till ith index can be formed
                // Only then there is a possibility of a word being formed starting from the (i+1) index
                if(dpArray[i]){
                    
                    int subStringLen = j - (i+1) +1;
                    string subString = s.substr(i+1, subStringLen);
                    
                    // if Substring starting from (i+1) till j is found in dictionary, 
                    // Only then, I can be sure that word from 0 till j index can be formed from the dictionary
                    if(mySet.find(subString) != mySet.end()) dpArray[j] = true;
                    
                    
                }
                
            }
            
            //printVector(dpArray);
            //cout << endl;
        }
        
        return dpArray[dpArray.size()-1];
    }
};