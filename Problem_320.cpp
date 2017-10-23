// Problem 320


using namespace std;

typedef vector<string> Vector;

class Solution {
public:

    void generateHelper(string & word, string abbr, int currLen, Vector & result, bool prevNum){
        
        /*
        
        1. A very good thing in this problem is to visualize how to write this backtracking function
        2. Otherwise, it is an easy problem
        3. Writing backtrcking is important here
        
        */
        
        //cout <<  "Abbr = " << abbr << ": CurrLen = " << currLen << ": PrevNum = " << prevNum << endl ;
        
        if(currLen == word.size()) {
            
            result.push_back(abbr);
            return;
        }
        
        generateHelper(word, abbr + word[currLen], currLen + 1, result, false);
        
        if(prevNum == false){
            
            int i = 1;
            while(i + currLen <= word.size()){
                
                generateHelper(word, abbr + to_string(i), currLen + i, result, true);
                i++;
                
            }
            
        }
        
    }
    
    vector<string> generateAbbreviations(string word) {
        
        Vector result;
        
        generateHelper(word, "", 0, result, false);
        
        return result;
        
    }
};