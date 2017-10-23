// Problem 214

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
    
    void buildKMPTable(string needle, Vector & table){
        
        
        // BUILDING THE LOOKUP TABLE
        //Vector table(needle.size(), 0);
        
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
        
        
    }
    
    string shortestPalindrome(string s) {
        
        
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        // Build an Appended string with reverse of Original String
        string total = s + "#" + rev_s;
        
        Vector table(total.size(), 0);
        
        
        
        buildKMPTable(total, table);
        
        //printVector(table);
        
        // How many chars to be included from the Reversed String into the original string to make it a Palindrome
        int includeNumChars = s.size() - table[total.size()-1];
        
        string temp = rev_s.substr(0, includeNumChars) ;
        
        //cout << "Temp = " << temp << endl;
    
        return temp + s;
        
    }
};