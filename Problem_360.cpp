// Problem 360


using namespace std;

typedef vector<int> Vector;

class Solution {
public:

    int evaluate(int x, int a, int b, int c){
        
        return  a*x*x + b*x + c;
        
    }
    
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        
        
        /*
        
        1. Very Simple Question
        2. Refreshses the Concepts of Quadratic Equations Graphs
        3. Key thing to note is why building result from high to low in one case from low to high in other case
        
        */
        
        if(nums.size() == 0) return nums;
        
        Vector result(nums.size(), 0);
        
        int i = 0;
        int j = nums.size()-1;
        
        
        if(a >= 0){
            
            int index = nums.size()-1;
            
            while(i <= j){
                
                if(evaluate(nums[i], a, b, c) > evaluate(nums[j], a, b, c)){
                    
                    result[index] =  evaluate(nums[i], a, b, c);
                    index--;
                    i++;
                    
                }
                
                else{
                    
                    result[index] = evaluate(nums[j], a, b, c);
                    index--;
                    j--;
                    
                }
                
                
            }
            
        }
        
        
        
        if(a < 0){
            
            int index = 0;
            
            while(i <= j){
                
                if(evaluate(nums[i], a, b, c) < evaluate(nums[j], a, b, c)){
                    
                    result[index] =  evaluate(nums[i], a, b, c);
                    index++;
                    i++;
                    
                }
                
                else{
                    
                    result[index] = evaluate(nums[j], a, b, c);
                    index++;
                    j--;
                    
                }
                
                
            }
            
        }
        
        
        return result;
        
    }
};