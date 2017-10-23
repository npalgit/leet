// Problem 384


using namespace std;

typedef vector<int> Vector;

class Solution {
    
private:

    Vector nums_copy, work_copy;
    
public:

    Solution(vector<int> nums) {

        srand (time(NULL));

        for(int i = 0; i < nums.size(); i++){
            
            nums_copy.push_back(nums[i]);
            work_copy.push_back(nums[i]);
            
        }
      
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        
        return nums_copy;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        
        for(int i = work_copy.size()-1; i > 0; i--){
            
            int randNum = rand() % (i+1);
            
            swap(work_copy[randNum], work_copy[i]);
            
        }
        
        return work_copy;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */