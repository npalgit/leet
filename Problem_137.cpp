// Problem 137

using namespace std;

typedef vector<int> Vector;

class Solution {
public:

    int singleNumber(vector<int>& nums) {
        
        
        
            int ones=0, twos =0;
            int common_bit_neg_mask;
            
            for(int i=0; i<nums.size();i++)
            {
              
              
                // Storing Common Bits of ones and Current Number in twos
                twos = twos | (ones & nums[i]);
                
                
                /* XOR the new bits with previous 'ones' to get all bits
                   appearing odd number of times
                */ 
               
                ones = ones ^ nums[i];
                 
                 
                 /* The common bits are those bits which appear third time
                    So these bits should not be there in both 'ones' and 'twos'.
                    common_bit_mask contains all these bits as 0, so that the bits can 
                    be removed from 'ones' and 'twos'   
                 */
     
                int common_bit_mask = (ones & twos);
                common_bit_neg_mask= ~common_bit_mask;
                
                
                //Remove common bits (the bits that appear third time) from 'ones'
                
                ones = ones & common_bit_neg_mask;
                
                
                // Remove common bits (the bits that appear third time) from 'twos'
                
                twos = twos & common_bit_neg_mask;
            }
            return ones;
        
       
        
    }
};