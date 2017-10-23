// Problem 215


typedef vector<int> Vector;
typedef priority_queue<int, Vector> PQueue;
class Solution {
public:


    void qsort(vector<int>& A, int left, int right) {
  if (left >= right) return;
  
  int middle = left + (right - left) / 2;
  swap(A[middle], A[left]);
  int midpoint = partition(A, left + 1, right, A[left]);
  swap(A[left], A[midpoint]);
  qsort(A, left, midpoint);
  qsort(A, midpoint + 1, right);
}

int partition(vector<int>& A, int left, int right, int who) {
  for (int i=left; i<right; ++i) {
    if (A[i] <= who) {
      swap(A[i], A[left]);
      left ++;
    }
  }
  return left - 1;
}



    void quickSort(Vector & nums, int left, int right){
        
        int i = left; int j = right;
        
        int temp;
        
        int pivot = nums[(left + right)/2];
        
        while(i <=j){
            
            while(nums[i] < pivot){
                i++;
            }
            
            while(nums[j] > pivot){
                
                j--;
            }
            
            if(i <= j){
                
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
                
            }
            
            
            if(left < j) quickSort(nums, left, j);
            
            if(i < right) quickSort(nums, i, right);
            
        }
        
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        
       /*
       1. Very simple question
       2. Build a Priority Q with Vector
       3. Syntax is important here.
       4. Logic seems simple.
       
       
       */
        
        
       /*
       PQueue myPQ(nums.begin(), nums.end());

        
        int count = 0;
        
        while(k!=1){
            
            myPQ.pop();
            k--;
            
        }
        
        return myPQ.top();
        
        */
        
        
        
        
        //sort(nums.begin(), nums.end());
        
        qsort(nums, 0, nums.size());
        
        return nums[nums.size()-k];
        
        
        
        
        
        
        
    }
};