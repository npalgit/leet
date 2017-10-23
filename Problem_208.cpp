// Problem 208

using namespace std;



class TrieNode {
    
    typedef unordered_map<char, TrieNode *> HashMap;
    private:
        HashMap myMap;
        bool end;
        
        
    public:
    
        TrieNode() {
        
            end = false;
        
        }
        
        friend class Trie;
};

class Trie{
    
private:
    TrieNode * root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        
        root = new TrieNode();
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        TrieNode * ptr = root;
        for(int i = 0; i < word.size(); i++) {
            
            if(ptr->myMap.find(word[i]) == ptr->myMap.end()){
                
                ptr->myMap[word[i]] =  new TrieNode();
                
            }
            
            
            ptr = ptr->myMap[word[i]];
        }
        
        ptr->end = true;
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        TrieNode * ptr = root;
        
        for(int i = 0; i < word.size(); i++) {
            
            if(ptr->myMap.find(word[i]) == ptr->myMap.end()){
                
                return false;
                
            }
            
            
            else ptr = ptr->myMap[word[i]];
        }
        
        if(ptr->end == true) return true;
        
        
        return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        
        TrieNode * ptr = root;
        
        for(int i = 0; i < prefix.size(); i++) {
            
            if(ptr->myMap.find(prefix[i]) == ptr->myMap.end()){
                
                return false;
                
            }
            
            
            else ptr = ptr->myMap[prefix[i]];
        }
        
        if(ptr->end == true || ptr->myMap.size()) return true;
        
        
        return false;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */