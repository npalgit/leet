// Problem 300

#include<algorithm>

using namespace std;

typedef vector<int> Vector;
typedef Vector::iterator VectorItr;

class Solution {
public:

    void printVector(Vector & myVect){
        
        
        cout << " Printing the Vector" << endl;
        
        for(auto x: myVect) cout << x << " : ";
        
        cout << endl;
    }
    
    int upperBoundBinSearch( Vector & nums, int target){
        
        int left = 0;
        int right = nums.size()-1;
        
        int mid = -1;
        
        while(left <= right){
            
            mid = (left + right)/2;
            if(target > nums[mid]) left = mid+1;
            else if(target < nums[mid]) right  = mid-1;
            else if(target == nums[mid]) return mid;
            
            
        }
        
        
        return left;
        
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        
        
        /*
        
        
        1. See the Page for Details.
        2. There is another method in O(nlogn)
        3. Do that method.
        4. this is only O(n*n)
        
        
        
        if(nums.empty()) return 0;
        Vector LS;
        
        LS.push_back(1);
        
        
        int value, maxNum  = 0;
        
        for(int i = 1; i < nums.size() ; i++){
            
            maxNum = 0;
            
            for(int j =0; j < i; j++){
                
                value = nums[i];
                
                if(value > nums[j]){
                    
                    maxNum  = max(maxNum, LS[j]);
                    
                }
                
                
                
            }
            
             maxNum = maxNum + 1;
            LS.push_back(maxNum);
        }
        
        //printVector(LS);
        
        int finalNum = INT_MIN;
        
        for( auto x : LS){
            
            finalNum = max(finalNum, x);
            
        }
        
        return finalNum;
        
        */
        
        
        // This is the O(nlogn) solution for this problem.
        // Above solution is O(n*n)
        
        if(nums.size() < 2) return nums.size();
        int finalNum = 0;
        
        Vector tails;
        
        
        for(auto x : nums){
            
            
            int index = upperBoundBinSearch(tails, x);
            
            
            
            if(index == tails.size()) tails.push_back(x);
            else tails[index] = x;
            
            //cout << "Element = " << x << ", Index = " << index << ", Tail Size = " << tails.size() << endl;
            //printVector(tails);
            //cout << endl;
            
            
            
        }
        
        
        return tails.size();
        
        
    }


};