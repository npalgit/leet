// Problem 28

using namespace std;


typedef vector<int> Vector;

class Solution {
public:

    void printVector(Vector & table){
        
         for(auto x: table){
            
            cout << x << " : ";
            
        }
        cout << endl;
        
    }
    
    
    int strStr(string haystack, string needle) {
        
        
        
        if(needle.empty()) return 0;
        
        // BUILDING THE LOOKUP TABLE
        Vector table(needle.size(), 0);
        
        int i = 1;
        int j = 0;
        
        while(i < needle.size()  ){
            
            
            if(needle[i] == needle[j]){
                
                table[i] = j +1;
                i++;
                j++;
                
            }
            
            
            else{
                
                
                if(j > 0){
                    
                    j = table[j-1];
                   
                }
                
                else i++;
                
            }
            
            
        }
        
        printVector(table);
       
        
        
        // SEARCHING THE SUBSTRING USING THE TABLE
        j = 0;
        i = 0;
        
        while(i < haystack.size()){
            
            
            if(haystack[i] == needle[j]) {
                
                // j has reached the end of the needle. Therefore, Match has occured
                // We subtract needle size from i and return to mark the starting of the substring in the haystack
                if(j == needle.size() - 1){
                    
                    return i - (needle.size()-1);
                }
                
                // Both are only incremented
                else {
                    
                    
                    i++;
                    j++;
                }
                
            }
            
            else {
             
                // this is only for the starting
                if(j == 0){
                    
                    i++;
                }   
                
                
                // If no match occurs, j moves to table[j-1]
                // Because, till table[j-1], match has already occured
                else {
                    
                    j = table[j - 1];
                    
                }
            }
            
            
            
        }
    
        return -1;
        
        
        
    }
};