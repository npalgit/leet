// Problem 15

#include<algorithm>
using namespace std;

typedef vector<int> Vector;
typedef vector<Vector> Matrix;
typedef Vector::iterator VectorItr;

class Solution {
public:

    // Simple Binary Search Algorithm
    int findinV(Vector& myVect, int target, int left){
        
        int mid; 
        //int left = 0; 
        int right = myVect.size()-1; 
         
        while(left <= right){ 
         
            mid = left + (right-left)/2; 
             
            if(myVect[mid] > target) right = mid-1; 
            else if(myVect[mid] < target) left = mid+1; 
            else if(myVect[mid] == target) return 1; 
     
        }
        
        return 0;
    }
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        Vector partial;
        Matrix table;
        
        sort(nums.begin(), nums.end());
        
        int initial_sum = 0, rqd = 0, sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            
            // To avoid the duplicates
            if(i >= 1 && nums[i] == nums[i-1]) continue;
            initial_sum = nums[i];
            
            for(int j = i + 1; j < nums.size(); j++){
                
                if( j != i+1 && j >= 1 && nums[j] == nums[j-1]) continue;
                sum = initial_sum +  nums[j];
                
                rqd = -1 *sum;
                
                if(rqd >= nums[j]){
                    if(findinV(nums, rqd, j+1)){
                        
                        //cout << initial_sum << " : " << nums[j] << " : " << rqd << endl;
                        partial.push_back(nums[i]);
                        partial.push_back(nums[j]);
                        partial.push_back(rqd);
                    }
                }
                
                if(partial.empty()== 0)table.push_back(partial);
                partial.clear();
                
            }
            
        }
        //sort(table.begin(), table.end());
        //table.erase(unique(table.begin(), table.end()), table.end());
        return table;
    }
};