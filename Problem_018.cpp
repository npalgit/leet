// Problem 18

using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;
typedef map<int, Matrix> HashMap;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    
        Matrix result;
        int n = nums.size();
        
        if(n<4)  return result;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-3; i++){
            
            if(i > 0 && nums[i]==nums[i-1])  continue;
          
            for(int j = i+1; j < n-2; j++){
                
                if(j > i+1 && nums[j]==nums[j-1])  continue;
          
                int start=j+1, end=n-1;
                
                while(start < end){
                  
                    int sum=nums[start]+nums[end]+nums[i]+nums[j];
                   
                    if(sum<target)  start++;
                    else if(sum>target)  end--;
                    else{
                        result.push_back(vector<int>{nums[i], nums[j], nums[start], nums[end]});
                       
                        start++; 
                        end--;
                        
                        while(nums[start-1]==nums[start] && start<end)  start++;
                        while(nums[end+1]==nums[end] && start<end)  end--;
                    }
                }
            }
        }
        
        return result;
    }
        
        
        
    
};