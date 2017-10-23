// Problem 370

using namespace std;

typedef vector<int> Vector;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {

        /*
        
        1. Very Good Question
        2. Requires thinking in terms of accumulating sum
        3. Learn this trick
        
        */
        Vector result(length, 0);
        
        // Build the Initial Result Vector
        for(int i = 0; i < updates.size(); i++){
            
            Vector update = updates[i];
            
            int startIndex = update[0];
            int endIndex = update[1];
            int incr = update[2];
            
            
            result[startIndex] = result[startIndex] + incr;
            
            if(endIndex < length - 1) result[endIndex + 1] = result[endIndex +1] - incr;
            
            
            
        }
        
        
        
        // Take the running sum for the Result Vector
        int sum = 0;
        for(int j = 0; j < result.size(); j++){
            
            result[j] = result[j] + sum;
            
            sum = result[j];
            
        }
        
        
        return result;
        
    }
};