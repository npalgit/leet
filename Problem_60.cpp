// Problem 60

using namespace std;

typedef vector<int> Vector;
typedef Vector::iterator VectorItr;

class Solution {
public:
    string getPermutation(int n, int k) {
    
        /*
        
        1. Simple Logic. We can reconstruct the string by calculating which character will come at what position
        2. See the solved example in MATHS
        
        */
    
        Vector myVect;
        VectorItr itr;
        
        string myString = "";    
        int fact = 1;
        for(int i=1 ; i <= n; i++){
            
            fact = fact * i;
            myVect.push_back(i);

        }

        
        
        int quot = 1, remdr = k;
        
        int start = n;
        itr = myVect.begin();
        
        while(myVect.size() != 1){
            
            itr = myVect.begin();
            
            fact = fact/start;

            
            quot = remdr/fact;
            remdr = remdr%fact;
            
            if( quot && remdr == 0) {
                quot--;
                remdr = fact;
            }

            
            advance(itr, quot);
            myString = myString + to_string(myVect[quot]);
            
            myVect.erase(itr);
          
            start--;
        }
        
        int last = myVect[0];
        
        myString = myString + to_string(last);

        return myString;
    
    }
};