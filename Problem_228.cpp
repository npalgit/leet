// Problem 228

using namespace std;

typedef vector<string> Vector;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        /*
        1. Simple Problem
        2. Corner Case dealing is important
        3. Important to see how you are dealing with the last element in the answer vector
        4. Not in NOTES as it is a simple problem
        
        */
        
        Vector result;
        if(nums.empty()) return result;
        
        int firstNum = nums[0];
        int secondNum = nums[0];
        
        string partial = "";
        string arrow = "->";
        
        
        

        
        for(int i = 1; i < nums.size(); i++){
            
        
            if(nums[i] - nums[i-1] != 1){
                
                secondNum = nums[i-1];
                
                if(firstNum != secondNum){
                    
                    partial = to_string(firstNum) + arrow + to_string(secondNum);
                }
                
                else {
                    partial = to_string(firstNum);
                }
                
                firstNum = nums[i];
                
                result.push_back(partial);
                partial.clear();
            }   
            
            
           
        }
        
        if(firstNum == nums.back()) result.push_back(to_string(firstNum));
        else {
            
            string finalString = to_string(firstNum) + arrow + to_string(nums.back());
            
            result.push_back(finalString);
            
        }
        
        return result;
        
    }
};