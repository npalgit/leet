// Problem 11

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        /*
        1. Very nice logic explained in Notes
        2. Done in 2 Pointers Section.
        3. It is pure trick logic and maths, but simple
        
        
        */
        
        int i = 0; int j = height.size()-1;
        
        int water  = 0;
        
        while(i < j){
            
            int h = min(height[i], height[j]);
            
            int width = j-i;
            
            water = max(water, h * width);
            
            while(i < j  && h>= height[i])i++;
            
            while(i < j  && h>= height[j])j--;
            
        }
        
        
        return water;
        
    }
};