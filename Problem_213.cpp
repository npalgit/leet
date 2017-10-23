// Problem 213

using namespace std;


typedef vector<int> Vector;

class Solution {
public:

    int helpRob(Vector & nums, int start, int end){
    
        if(nums.empty()) return 0;
        if(end < start) return 0;
        
        int temp;
        
        int result;
        
        int include_LastHouse = 0;
        int exclude_LastHouse = 0;
        
        for(int i = start; i <=end; i++){
            
            temp = include_LastHouse;
            
            
            include_LastHouse = nums[i] + exclude_LastHouse;
            
            exclude_LastHouse = max(temp, exclude_LastHouse);
            
            
            
            result = max(include_LastHouse, exclude_LastHouse);
            
            //cout << "Till " << nums[i] << " : " <<  "Temp  = " << temp << ", Include = " << include_LastHouse << ", Exclude = " << exclude_LastHouse <<", Result = " << result << endl;
        }
        
        
        
        return result;    
        
        
    }
    
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        
        int result_1 = helpRob(nums, 0, nums.size()-2);
        int result_2 = helpRob(nums, 1, nums.size()-1);
        
        //cout << "Result 1  = " << result_1 << endl;
        //cout << "Result 2  = " << result_2 << endl;
        
        
        return max(result_1, result_2);
        
    }
};