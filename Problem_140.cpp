// Problem 140

using namespace std;

typedef unordered_set<string> Set;
typedef vector<string> Vector;


class Solution {
    
private:
    //Set mySet;
    int effort;
    
public:

    void createSet(Vector & wordDict, Set & mySet) {
        
        for(auto x : wordDict) mySet.insert(x);
        
    }

    void helpBreak(string & s, int left, string path, Set & mySet, Vector & answer ) {
        
        
        if (--effort <= 0) {
            return;
        }
        
        if(left == s.size()) {
            
            // Corner Case Check
            path = path.erase(0,1);
            answer.push_back(path);
            effort = effort + 100;
            return;
        }
        
        
        //int wordLen = 0;
        
        for(int i = 0; left + i <= s.size(); i++) {
            
        
            string subString = s.substr(left, i);
            //cout << "Substring = " << subString << endl;
            
            if(mySet.find(subString) != mySet.end()){
                
                string oldPath = path;
                
                // Corner Case Check
                //if(path != "") path = path + " " + subString;
                //else path = path + subString;
                path = path  + " " + subString;
                
                //cout << "New Call" << ", Path  = " << path << endl;
                helpBreak(s, left + i, path, mySet, answer);
                
                // This is important in almost every DFS problem
                // Replacing the modified input with the original input to let the function continue properly
                // This is almost same as pop_back in vectors
                path = oldPath;
                
                
            }
            
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        Set mySet;
        createSet(wordDict, mySet);
        
        Vector answer;
        effort = 100;
        string path  = "";
        
        helpBreak(s, 0, path, mySet, answer);
        
       
        return answer;
       
    }
};