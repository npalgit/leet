// Problem 115

using namespace std;


typedef vector<int> Vector;

class Solution {
public:

    void printVector(Vector & myVect){
        
        for(auto x : myVect){
            
            cout << x << " : "; 
        }
        
        cout << endl << endl;
        
    }
    
    
    int numDistinct(string s, string t) {
        
        /*
        
        // Question : How many t subsequence we can find in s ?
        
        int tLen = t.size();
        int sLen = s.size();
        
        if(s.empty() && t.empty()) return 1;
        
        int add;
        
        Vector cur(tLen, 0);
       
        
        for (int sIndex = 0; sIndex < sLen; sIndex++) {
            
            // Because Null Strings are also a subsequence of each other
            int previousTemp = 1;
            
            for (int tIndex = 0; tIndex < tLen; tIndex++) {
                
                int temp = cur[tIndex];
                
                // If Characters are same, just propagate Add Previously found subsequences to the current
                // subsequences
                if(t[tIndex] == s[sIndex]) add = previousTemp;
                else add = 0;
                
                cur[tIndex] = cur[tIndex] + add;
                
                
                
                
                cout << "sIndex = " << sIndex << ", tIndex = " << tIndex << endl;
                cout << "Previous Temp = " << previousTemp << ", Temp = " << temp << ", Add = " << add << endl;
                printVector(cur);
                
                // Previous Depends on the earlier value of current, and not on the updated value of the current
                previousTemp = temp;
                
                
            }
            
            cout << "##############################################" << endl;
        }
        
        return cur[tLen-1];
        
        */
        
        
        
        
        int tLen = t.size();
        int sLen = s.size();
        
        if(s.empty() && t.empty()) return 1;
        
        int add;
        
        Vector currIter(tLen+1, 0);
        Vector prevIter(tLen+1, 0);
        prevIter[0] = 1;
        currIter[0] = 1;
       
        
        for (int sIndex = 1; sIndex <= sLen; sIndex++) {
            
            // Because Null Strings are also a subsequence of each other
            
            for (int tIndex = 1; tIndex <= tLen; tIndex++) {
                
                
                
                // If Characters are same, just propagate Add Previously found subsequences to the current
                // subsequences
                if(t[tIndex-1] == s[sIndex-1]) {
                    
                    currIter[tIndex] = currIter[tIndex] + prevIter[tIndex-1];
                    
                }
                
                
               // cout << "sIndex = " << sIndex << ", tIndex = " << tIndex << endl;
                
               //printVector(prevIter);
               //printVector(currIter);
                
                
                
                
            }
            
            prevIter = currIter;
           
            
            //cout << "##############################################" << endl;
        }
        
        return currIter[tLen];
        
        
        
        
        
    }
};