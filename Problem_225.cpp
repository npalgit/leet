// Problem 225

using namespace std;

typedef queue<int> Queue;


class MyStack {
    
private:
    Queue myQ;
    Queue copyQ;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        
        myQ.push(x);
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        
        int lastElem = 0;
        while(myQ.size()) {
            
            lastElem = myQ.front();
            if(myQ.size() > 1)copyQ.push(lastElem);
            myQ.pop();
            
            
        }
        
        while(copyQ.size()) {
            
            myQ.push(copyQ.front());
            copyQ.pop();
            
            
        }
        
        return lastElem;
        
    }
    
    /** Get the top element. */
    int top() {
        
        int lastElem = 0;
        
        while(myQ.size()) {
            
            lastElem = myQ.front();
            myQ.pop();
            copyQ.push(lastElem);
            
            //if(myQ.size() > 1)copyQ.push(lastElem);
            
        }
        
        while(copyQ.size()) {
            
            myQ.push(copyQ.front());
            copyQ.pop();
            
            
        }
        
        return lastElem;
        
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        
        return myQ.empty();
        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */