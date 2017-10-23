// Problem 187

using namespace std;

typedef bitset< 1<<20 > BitMap;
typedef vector<string>  Vector;

class Solution {
public:

    int char2val(char c) {
        
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
    
        }
    
        return -1;
        
        
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        
        /*
        1. For this question, check the comments for each line
        2. See notes for theory
        3. Solved in BITS
        
        */
        Vector result;
        
        if (s.size() <= 10)
        return result;
        
        
       
        BitMap S1;
        BitMap S2;
        
        int val = 0;
        for (int i=0; i < 10; i++){
            
            // Calc. the has value for the first string.
            
            val = (val << 2) | char2val(s[i]);
            
           // cout << "Char  = " << s[i] << " : " <<val << endl;
            
        }   
        
        // S1 now contains the val bit set to 1, corresponding to the first sequence
        S1.set(val);
        //cout << val << " | ";
        
        
        // Mask Created to calculate the integer value of the running string considering only last 10 chars
        int mask = (1 << 20) - 1;
        
        
        // Calculate the value in running fashion by incrementing each char of the string
        for (int i=10; i < s.size(); i++) {
            
            // Calc the hash value for the string ending at position i
            val = ((val << 2) & mask) | char2val(s[i]);  
            
            // S2 is a bitmap to store if the value has already been added to the result vector
            if (S2[val])
                continue;
               
            // S1 bitmap is used as a HashMap. If found in S1, that means substring was already there 
            if (S1[val]) {
                
                result.push_back(s.substr(i-10+1, 10));
                
                // Once Found in S1, put the bit to 1 in S2 to avoid duplication in result vector
                S2.set(val);
                
            }
            
            else{
            
                // If this is the first time sequence is encountered, val bit in S1 is set to 1
                S1.set(val);
                
            }
            
        }
       
       
        return result;
}
        
    
};