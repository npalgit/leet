// Problem 296

using namespace std;

typedef vector<int> Vector;
class Solution {
    
public:

   

    int partition2(Vector & nums, int left, int right){
        
        if(nums.size() == 0) return -1;
        
        int pivot = nums[left];
        
        int i = left + 1;
	    int j = left + 1;
        
        for(j; j <= right; j++){
            
            
            if(nums[j] < pivot) {
                
                swap(nums[i], nums[j]);
                i++;
            }
        }
        
        swap(nums[left], nums[i-1]);
        return i-1;
        
    }
    

    int kthSmallest(Vector & nums, int left, int right, int k ){
        
        //cout << "Left = " << left << " : " << "Right = " << right << endl;
          if(left <= right &&  k > 0 ){

            int pivotPosn = partition2(nums, left, right);
            
           // cout << "Position  = " << pivotPosn << endl;
            
            
            if (pivotPosn == k-1) return nums[pivotPosn];
                
            if (pivotPosn > k-1)  return kthSmallest(nums, left, pivotPosn, k);
     
            else return kthSmallest(nums, pivotPosn+1, right, k);
            
        }
    
     
        return INT_MAX;
        

    }

    int findMedian(Vector & nums){
        
        return kthSmallest(nums, 0, nums.size()-1, nums.size()/2 + 1);
        
    }

    int minTotalDistance(vector<vector<int>>& grid) {
        
        if(grid.empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        Vector posnsR, posnsC;
        for(int i = 0; i < rows; i++){
            
            for(int j = 0; j < cols; j++){
                
                if(grid[i][j] ==1){
                    
                    posnsR.push_back(i);
                    posnsC.push_back(j);
                }
                
            }
        }
        
        // posnsR is already sorted if we observe clearly how is it created
        int medRow = posnsR[posnsR.size()/2];
        
        // But, we need to find the Median of posnsC in Linear Time
        
        // Method 1 : O(nlogn) : Sort + find element at half position
        //sort(posnsC.begin(), posnsC.end());
        //int medCol = posnsC[posnsC.size()/2];
        
        
        // Method 2 : O(n)  : Partition and find Kth element in Array by Quick Sort Algorithm
        // Refer Question 462
        int medCol = findMedian(posnsC);
        
        int total = 0;
        
        for(auto x : posnsR) total = total + abs(x - medRow);
        for(auto x : posnsC) total = total + abs(x - medCol);
        
        return total;
        
        
    }
};