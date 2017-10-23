// Problem 146

using namespace std;

typedef list<int> List;
typedef List::iterator ListItr;
typedef pair<int, ListItr> Pair;
typedef unordered_map<int, Pair>  HashMap;



class LRUCache {
    
private:

    int cache_capacity;
    List myList;
    HashMap myMap;
    
public:

    LRUCache(int capacity) 
    :
    cache_capacity(capacity)
    {
        
    }
    
    int get(int key) {
        
        /*
        
        1. This is a very good question.
        2. Key to think is that we need to do both the operations in O(1).
           Hence, we will use a list that can do both insert and delete in O(1)
           
        */
        
        
        if(myMap.find(key) == myMap.end()) return -1;
        
        // If Key Found, Update the Counter and then return value
        Pair presentPair = myMap[key];
        
        // Updating the Counter
        ListItr itr = presentPair.second;
        int value = presentPair.first;
        myList.erase(itr);
        
        myList.push_back(key);
        itr = myList.end();
        itr--;
        myMap[key] = make_pair(value, itr);
        
        
        
        
        return value;
        
    }
    
    void put(int key, int value) {
        
        // If key Not found in Cache, then Insert
        if(myMap.find(key) == myMap.end()){
            
            myList.push_back(key);
            ListItr itr = myList.end();
            itr--;
            myMap[key] = make_pair(value, itr);
            
            
        }
        
        
        else{
            
            // If Key is found in Cache, then update counter
            Pair presentPair = myMap[key];
            ListItr itr= presentPair.second;
            myList.erase(itr);
            
            
            myList.push_back(key);
            itr = myList.end();
            itr--;
            myMap[key] = make_pair(value, itr);
            
            
        }
        
        // If Cache size exceeded, then Evict Least Recently Used Key
        if(myMap.size() > cache_capacity){
            
            int evictKey = myList.front();
            myList.pop_front();
            myMap.erase(evictKey);
            
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */