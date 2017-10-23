// Problem 189

using namespace std;

typedef vector<int> Vector;
typedef Vector::iterator VectorItr;

class Solution {
public:

    void printVector(Vector & myVect) {
        
        for(auto x : myVect) {
            
            cout << x << " : ";
        }
        
        cout << endl;
    }
    void reverse(Vector & nums, int left, int right) {
        
        while(left <= right) {
            
            int temp = nums[right];
            nums[right] = nums[left];
            nums[left] = temp;
            
            left++;
            right--;
            
        }
        
    }
    void rotate(vector<int>& nums, int k) {
        
        // 1. This is O(n) time and O(n) space solution
        /*
        k = k % nums.size();
        
        int insert = nums.size() - k;
        
        
        for(int i = 0; i < insert; i++) {
            
            nums.push_back(nums[i]);
            
        }
        
        nums.erase(nums.begin(), nums.begin() + insert);
        
        */
        
        
        
        // 2. This is O(n) time and O(1) space solution
        k = k % nums.size();
        
        //printVector(nums);
        reverse(nums, 0, nums.size() - 1 - k);
        //printVector(nums);
        
        reverse(nums, nums.size() - k, nums.size()-1);
       // printVector(nums);
        reverse(nums, 0, nums.size()-1);
       // printVector(nums);
        
    }
};