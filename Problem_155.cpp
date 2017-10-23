// Problem 155

using namespace std;

typedef pair<int, int> Pair; 
typedef stack<Pair> Stack;

class MinStack {


    
private:

    Stack myStack;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
       
   
    }
    
    void push(int x) {
        
        if(myStack.empty()) myStack.push(make_pair(x,x));
        
        else{
            
            int min = myStack.top().second;
            
            if(x < min) myStack.push(make_pair(x,x));
            else myStack.push(make_pair(x, min));
            
        }
        
        
    }
    
    void pop() {
        
        
        myStack.pop();
        
    }
    
    int top() {
        

        return myStack.top().first;
        
    }
    
    int getMin() {
        
      
        return myStack.top().second;
        
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */