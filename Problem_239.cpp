// Problem 239

using namespace std;

typedef vector<int> Vector;
typedef pair<int, int> Pair;
typedef deque<Pair> DQ;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        /*
        1. This problem involves a classic concept
        2. Should be remembered.
        
        */


        Vector answer;
        DQ window;
        
        for(int i = 0; i < nums.size(); i++){
            
            // if it is changed to >=, it would be then a SLIDING WINDOW MINIMUM
            while(window.size() && window.back().first <= nums[i]){
                
                window.pop_back();
                
            }
            
            
            window.push_back(make_pair(nums[i], i));
            
            // Checking that our front element is still in window, else, it is popped
            while( i - window.front().second >= k){
                
                window.pop_front();
            }
            
            
            answer.push_back(window.front().first);
           
        }
        
        // Removing Initial Elements in answer that creeped when window was building initially
        int j = k-1;
        while(j > 0){
            
            answer.erase(answer.begin());
            j--;
        }
        
        return answer;
    }
};