// Problem 84

using namespace std;


typedef stack<int> Stack;
typedef vector<int> Vector;

class Solution {
public:


    void calcArea(Stack & myStack, Vector & heights, int i, int & maxArea){
        
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
        maxArea = max(currArea, maxArea);
        
        
        
        //cout << "Current Area = " << currArea << ", Max Area = " << maxArea << endl;
        //cout << " ############  Coming Out  #########" << endl << endl;
        
        
    }
    int largestRectangleArea(vector<int>& heights) {
        
        Stack myStack;
        if(heights.empty()) return 0;
        
       int maxArea = 0;
       int topIndex;
       int topBarHeight;
       
       
       
       int i = 0;
       
       while(i < heights.size()){
           
           
           if(myStack.empty() || heights[myStack.top()] < heights[i]){
               
              // cout << "Pushing into Stack = " << i << ", Height of Bar = " << heights[i] <<endl;
               myStack.push(i);
               i++;
               
           }
           
           else {
               
               calcArea(myStack, heights, i, maxArea);
               
           }
           
       }
       
       //cout << endl << " $$$$$$$$$$$$$$$$$$$$$$$$$    Increasing Areas all Completed $$$$$$$$$$$$$$$$$$$$$" << endl;
       
       while(myStack.size()){
           
           calcArea(myStack, heights, i, maxArea);
           
           
       }
       
       
       return maxArea;
        
    }
};