// Problem 85

using namespace std;

typedef vector<char> Vector;
typedef vector<Vector> Matrix;
typedef vector<int> IntVector;
typedef stack<int> Stack;

class Solution {
public:


    int calcArea(Stack & myStack, IntVector & heights, int i){
        
        //cout << endl << " ############  Calculating Area  #########" << endl;
        int width;
        int topIndex = myStack.top();
         int topBarHeight  = heights[topIndex];
        myStack.pop();
        
        //cout <<"Top Index = " << topIndex << ", i = " << i << endl;
        //cout <<"Top Index = " << topIndex << ", Top Bar Height = " << topBarHeight << endl;
        //cout << "Stack Empty After Pop =  " << myStack.empty() << endl;
        
        
        if(myStack.empty()) width = i;
        else width = i - 1 - myStack.top();
        
        //if(myStack.size()) cout << "Stack Top Index = " << myStack.top() << endl;
        //cout << "Width = "  << width << endl;
        
              
       
        
        int currArea = topBarHeight * width;
        return currArea;
        
        
        
        
        
        //cout << "Current Area = " << currArea << ", Max Area = " << maxArea << endl;
        //cout << " ############  Coming Out  #########" << endl << endl;
        
        
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        Stack myStack;
        if(heights.empty()) return 0;
        
       int maxArea = 0;
       int topIndex;
       int topBarHeight;
       int currArea;
       
       
       int i = 0;
       
       while(i < heights.size()){
           
           
           if(myStack.empty() || heights[myStack.top()] < heights[i]){
               
              // cout << "Pushing into Stack = " << i << ", Height of Bar = " << heights[i] <<endl;
               myStack.push(i);
               i++;
               
           }
           
           else {
               
               currArea = calcArea(myStack, heights, i);
               maxArea = max(maxArea, currArea);
               
           }
           
       }
       
       //cout << endl << " $$$$$$$$$$$$$$$$$$$$$$$$$    Increasing Areas all Completed $$$$$$$$$$$$$$$$$$$$$" << endl;
       
       while(myStack.size()){
           
           currArea = calcArea(myStack, heights, i);
           maxArea = max(maxArea, currArea);
           
           
       }
       
       
       return maxArea;
        
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxArea = 0;
        if(matrix.empty() || matrix[0].empty()) return maxArea;
        
        IntVector heights(matrix[0].size(), 0);
        
        for(int i = 0; i < matrix.size(); i++){
            
            for(int j = 0; j < matrix[0].size(); j++){
                
                
                if(matrix[i][j] == '0')heights[j] = 0;
                else if(matrix[i][j] == '1') heights[j]++;
                
                
            }
            
            // Update Current Area and Max Area after every Row
            // Hence, we can be sure to catch the maxArea at least in any iteration 
            int currArea = largestRectangleArea(heights);
            maxArea = max(maxArea, currArea);
            
            
        }
        
        
        
        
        return maxArea;
        
    }
};