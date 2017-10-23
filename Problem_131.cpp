// Problem 131

using namespace std;

typedef vector<string> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:

    bool isPalindrome(string s) {
        
        int left = 0;
        int right = s.size()-1;
        
        while(left <= right){
            
            if(s[left] != s[right]) return false;
            left++;
            right--;
            
        }
        
        return true;
        
    }
    
    void dfs(string & s, int index, Vector & path, Matrix & result) {
        
        if(index == s.size()) {
            
            result.push_back(path);
            return;
        }
        
        
        for(int i = index; i < s.size(); i++) {
            
            string subString = s.substr(index, i-index+1);
            
            //cout << "Index = " << index << ", i = " << i <<", SubString = " << subString << endl;
            
            if(isPalindrome(subString)) {
                
                //string leftSubString = s.substr(index, i-index+1 );
                //cout << "Palindrome" << endl;
                path.push_back(subString);
                dfs(s, i+1, path, result);
                path.pop_back();
                
            }
            
        }
        
        //cout << "Out of for Loop" << endl;
        
    }
    vector<vector<string>> partition(string s) {
        
        Matrix answer;
        if(s.empty()) return answer;
        
        Vector path;
        
        dfs(s, 0, path, answer);
        
        return answer;
        
    }
};