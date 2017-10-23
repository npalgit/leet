// Problem 462

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



    /*
    int partition(Vector & nums, int left, int right){
        
        //if(left == right) return nums[left];
        if(nums.size() == 0) return -1;
        
        int pivot = nums[left];
        //swap(nums[left], nums[right]);
        
        int i = left + 1;
        int j = right;
        
        while(i < j){
            
            
            while(nums[i] < nums[pivot] && i < right) i++;
            
            while(nums[j] > nums[pivot] && j >= left) j--;
            
            if(i < j) swap(nums[i], nums[j]);
            
        }
        swap(nums[pivot], nums[j]);
        return j-1;
        
    }
    
    */
    
    int kthSmallest(Vector & nums, int left, int right, int k ){
        
        
        if(left <= right &&  k > 0 ){

            int pivotPosn = partition2(nums, left, right);
            
            
            
            
            if (pivotPosn == k-1) return nums[pivotPosn];
                
            if (pivotPosn > k-1)  return kthSmallest(nums, left, pivotPosn, k);
     
            else return kthSmallest(nums, pivotPosn+1, right, k);
            
        }
    
     
        return INT_MAX;
        

    }

    int findMedian(Vector & nums){
        
        return kthSmallest(nums, 0, nums.size()-1, nums.size()/2 + 1);
        
    }
    
    
    int minMoves2(vector<int>& nums) {
        
        
        /*
        1. Logic is very simple in this question
        2. The minimum distance required is the sum of absolute differences to the median of the array
        
        */
        
        int median = findMedian(nums);
        
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            
            sum = sum + abs(nums[i] - median);
            cout << "Sum = " << sum << endl;
            
        }
        
        
        return sum;    
    }
};