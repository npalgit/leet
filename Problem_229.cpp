// Problem 229

using namespace std;

typedef vector<int> Vector;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        
        /*
        1. Boyer Moore Majority Vote Algorithm
        2. Corner Cases are a bit peculiar
        3. Solved in ARRAY
        
        
        
        */
        if(nums.empty()) return nums;
        if(nums.size() < 2) return nums;
        
        //cout << "Size = "  << nums.size() << endl;
        
        int candOne = nums[0];
        int candTwo = nums[0];
        
        int countOne = 0;
        int countTwo = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(candOne == nums[i]) countOne++;
            else if (candTwo == nums[i]) countTwo++;
            
            else if (countOne == 0) {
                
                candOne = nums[i];
                countOne = 1;
            }
            
            
            else if(countTwo == 0) {
                
                candTwo = nums[i];
                countTwo = 1;
                
                
            }
            
            else{
                countOne--;
                countTwo--;
                
            }
            
        }
        
        
        
        countOne = 0;
        countTwo = 0;
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] == candOne) countOne++;
            if(nums[i] == candTwo) countTwo++;
            
            
            
        }
        
        Vector result;
        
        if(countOne > nums.size()/3) result.push_back(candOne);
        if(countTwo > nums.size()/3 && candOne != candTwo) result.push_back(candTwo);
        
        
        return result;
        
    }
};