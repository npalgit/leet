// Problem 303

using namespace std;

typedef vector<int> Vector;

class NumArray {
private:
    Vector result;
    
public:
    
    
    NumArray(vector<int> nums) {
        
        int temp = 0;
        for(auto x : nums){
            
            result.push_back(temp + x);
            temp = temp + x;
        }
        
        
        
    }
    
    int sumRange(int i, int j) {
        
        return result[j] - result[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */