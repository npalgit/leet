// Problem 167

#include<vector>
using namespace std;

class Solution {
public:

    typedef vector<int> Vector;
    typedef Vector::iterator VectItr;
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        
            Vector ansVect;
            int low = 1;
            int high = numbers.size();
            
            VectItr lowItr = numbers.begin();
            VectItr highItr = numbers.end();
            highItr--;
           
    
            
            while(lowItr < highItr) {
            
                while((lowItr < highItr) && ((*lowItr + *highItr) < target) ) {
                    lowItr++;
                    low++;
                    
                }
                
                
                while((lowItr < highItr) && ((*lowItr + *highItr)> target) ) {
                    highItr--;
                    high--;
                    
                }
        
        
                if((*lowItr + *highItr) == target && (lowItr != highItr)) {
                    
                  
                    ansVect.push_back(low);
                    ansVect.push_back(high);
                    lowItr++;low++;
                    highItr--;high--;
                    
                    
                }
            
            }
            
            return ansVect;
        
    }
    
    
    
    
    
};