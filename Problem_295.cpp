// Problem 295

using namespace std;

typedef vector<int> Vector;
typedef priority_queue<int, Vector, greater<int>> MinPQ;
typedef priority_queue<int, Vector, less<int>> MaxPQ;

class MedianFinder {
    
private:

    int size;
    MinPQ minPQ;
    MaxPQ maxPQ;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
        size = 0;
    }
    
    void pushInMinPQ(int num){
        
        if(minPQ.size() > maxPQ.size()){
            
            int topMin = minPQ.top();
            minPQ.pop();
            
            maxPQ.push(topMin);
            
            minPQ.push(num);
            
            
        }
        
        else {
            
            minPQ.push(num);
        }
        
    }
    
    void pushInMaxPQ(int num){
        
        if(maxPQ.size() > minPQ.size()){
            
            int topMax = maxPQ.top();
            maxPQ.pop();
            
            minPQ.push(topMax);
            
            maxPQ.push(num);
            
            
        }
        
        else {
            
            maxPQ.push(num);
        }
        
    }
    
    void addNum(int num) {
        
        //cout << "Push = " << num << endl;
        
        if(minPQ.empty()) {
         
            minPQ.push(num);
            size++;
            return;
            
        }
        
        int topMin = minPQ.top();
        
        if(minPQ.size() && maxPQ.empty()){
            
            if(num >= minPQ.top()){
                
                maxPQ.push(topMin);
                
                minPQ.pop();
                minPQ.push(num);
            }
            
            else maxPQ.push(num);
            size++;
            return;
            
        }
        
        //int topMax = maxPQ.top();
        
        
        
        // Case 1:
        if(maxPQ.top() == minPQ.top()){
            // There will be 3 sub-cases of Case 1 as well
            
            if(num < minPQ.top()){
                // Element will go to maxPQ
                
                pushInMaxPQ(num);
                
            }
            
            else if(num > minPQ.top()){
                // Element will go to minPQ
                
                pushInMinPQ(num);
                
            }
            
            else if(num == minPQ.top()){
                // Decision will be based on size
                
                if(minPQ.size() > maxPQ.size()) maxPQ.push(num);
                else if(minPQ.size() < maxPQ.size()) minPQ.push(num);
                else if(minPQ.size() == maxPQ.size()) minPQ.push(num);
                
            }
            
            size++;
            return;
            
            
        }
        
        
        // Case 2:
        if(num >= minPQ.top()){
            // Element will go to minPQ
            
            pushInMinPQ(num);
            
            
            size++;
            return;
            
            
        }
        
        
        // Case 3:
        else if(num > maxPQ.top() && num < minPQ.top()){
            
            // Decision will be based on size
            if(maxPQ.size() >= minPQ.size()){
                
                minPQ.push(num);
                
            }
            
            else {
                
                
                maxPQ.push(num);
                
            }
            
            
            size++;
            return;
            
        }
        
        // Case 4:
        else if(num <= maxPQ.top()){
            
            // Element will go to maxPQ
            pushInMaxPQ(num);
            size++;
            return;
            
        }
        
        
        
        
    }
    
    double findMedian() {
        
        
        //if(minPQ.size())cout << "Min PQ = " << minPQ.size() <<" :  " << minPQ.top()<< " ------- ";
        //if(maxPQ.size())cout << "Max PQ = " << maxPQ.size() <<" :  " << maxPQ.top()<< " ------- ";
        
        
        double answer = 0.0;
        
        if(size % 2){ // Odd Number of Total Elements
            
            if(minPQ.size() > maxPQ.size()){
                
                answer = minPQ.top();
                
            }
            
            else if (minPQ.size() < maxPQ.size()){
                
                answer = maxPQ.top();
                
            }
            
        }
        
        else{ // Even Number of Total Elements
                
                answer = minPQ.top() + maxPQ.top();
                answer = answer/2;
         
        }
        
        //cout << ", Median = " << answer << endl <<  endl;
        return answer;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */