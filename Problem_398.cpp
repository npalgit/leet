// Problem 398

using namespace std;

typedef vector<int> Vector;
class Solution {
public:
    Vector v;
    Solution(vector<int> nums) {
        
        v = nums;
        
        
    }
    
    int pick(int target) {
        
        int result = -1;
        int count = 0;
        
        for(int i=0; i< v.size(); i++) {
            
            if(v[i]!=target) {
                continue;
            }
        
            count++;
            
            int random = rand()%count;
            
            if(random == 0) {
                result = i;
            }
            
            //cout << "Count = " << count <<", Random Value = "<< random << ", Result = " << result << endl;
        }
        
        
        //cout << "Random = " << rand() % 30;
        return result;
        
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */