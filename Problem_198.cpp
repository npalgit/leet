// Problem 198

using namespace std;


class Solution {
public:

    int rob(vector<int>& nums) {
        
        if(nums.empty()) return 0;
        
        int temp;
        
        int result;
        
        int include_LastHouse = 0;
        int exclude_LastHouse = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            temp = include_LastHouse;
            
            
            include_LastHouse = nums[i] + exclude_LastHouse;
            
            exclude_LastHouse = max(temp, exclude_LastHouse);
            
            
            
            result = max(include_LastHouse, exclude_LastHouse);
            
            //cout << "Till " << nums[i] << " : " <<  "Temp  = " << temp << ", Include = " << include_LastHouse << ", Exclude = " << exclude_LastHouse <<", Result = " << result << endl;
        }
        
        
        
        return result;
        
        // [10, 20, 30, 2, 5, 42, 23, 6, 5, 28]
        
    }
};