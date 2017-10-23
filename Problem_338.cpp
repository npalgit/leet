// Problem 338


using namespace std;

typedef vector<int> Vector;

class Solution {

public:
    vector<int> countBits(int num) {

    Vector myVect;
    int start = 0;
    
    while(num >= start) {
        
        myVect.push_back(giveSetBits(start));
        start++;
        
    }
     
     return myVect;
    }

    int giveSetBits(int num) {


        int count = 0;
    
        while(num != 0) {
    
            num = num & (num-1);
    
            count++;
    
    
        }   

    return count;
}

    
};

