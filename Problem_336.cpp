// Problem 336


using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;
typedef unordered_map<string, int> HashMap;

class TrieNode {
public:
    
    
    unordered_map<char, TrieNode*> myMap;
    bool end;
    int index;
    
    TrieNode() {
        
        end = false;
        
    }
    
};


class Solution {
public:

    bool isPalindrome(string & myStr){
        
        int left = 0;
        int right = myStr.size() - 1;
        
        while(left <= right ){
            
            if(myStr[left] != myStr[right]) return false;
            else{
                
                left++;
                right--;
            }
            
        }
        
        return true;
        
        
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        
      
        Matrix table;
        HashMap myMap;
        Vector row;
        
        // Build the Hash Map:
        // Key = Reversed Word of the vector
        // Value = Index Value in the Input Vector
        for(int i = 0; i < words.size(); i++){
            
            string key = words[i];
            reverse(key.begin(), key.end());
            myMap[key] = i;
            
        }
        
        
        // If the Input Vector also contains a NULL string, then we have to additionally look for all the 
        // words that are a Palindrome themselves
        if(myMap.find("") != myMap.end()) {
            
            
            for(int i = 0; i < words.size(); i++){
                
                
                if(i == myMap[""]) continue;
                else {
                    
                    if(isPalindrome(words[i])) {
                     
                        row.clear();
                        row.push_back(myMap[""]);
                        row.push_back(i);
                        table.push_back(row);
                        
                    }
                    
                    
                }
                
            }
            
            
        }
        
        
        
        
        
        for(int i = 0; i < words.size(); i++){
            
            
            for(int j = 0; j < words[i].size(); j++){
                
                
                // Break down each word at every index into left and right
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size()-j);
                
                
                // Reverse of left occurs in myMap
                // Therefore, Palindrome Pair of right exists
                // Palindrome Pair exists if one of the broken part is has a palindrome, other part is a palindrome in itself,
                // and index of broken part is not current index. This is to avoid the NULL string.
                if(myMap.find(left) != myMap.end() && isPalindrome(right) && myMap[left] != i){
                    
                    row.clear();
                    row.push_back(i);
                    row.push_back(myMap[left]);
                    table.push_back(row);
                    
                }
                
                
                // Reverse of right occurs in myMap
                // Therefore, Palindrome Pair of left exists
                // Palindrome Pair exists if one of the broken part is has a palindrome, other part is a palindrome in itself,
                // and index of broken part is not current index. This is to avoid the NULL string.
                if(myMap.find(right) != myMap.end() && isPalindrome(left) && myMap[right] != i){
                    
                    row.clear();
                    
                    row.push_back(myMap[right]);
                    row.push_back(i);
                    
                    table.push_back(row);
                    
                }
                
                
                
            }
            
        }
        
        
        return table;
        
       
        
        
        
        
       
        
      
    
    
        
        
        
    }
};