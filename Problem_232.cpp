//Problem 232

using namespace std;

typedef stack<int> Stack;
class MyQueue {
    
private:
    
    Stack myStack;
    Stack copyStack;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        
        myStack.push(x);
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        
        //if(myStack.empty()) return 0;
        
        while(myStack.size()){
            
            copyStack.push(myStack.top());
            myStack.pop();
            
        }
        
        int value = copyStack.top();
        copyStack.pop();
        
        
        while(copyStack.size()){
            
            myStack.push(copyStack.top());
            copyStack.pop();
            
        }
        
        
        return value;
        
        
        
    }
    
    /** Get the front element. */
    int peek() {
        
        
        //if(myStack.empty()) return 0;
        
        while(myStack.size()){
            
            copyStack.push(myStack.top());
            myStack.pop();
            
        }
        
        int value = copyStack.top();
        //copyStack.pop();
        
        
        while(copyStack.size()){
            
            myStack.push(copyStack.top());
            copyStack.pop();
            
        }
        
        
        return value;
        
        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        
        return myStack.empty();
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */