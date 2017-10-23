// Problem 57

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
typedef vector<Interval> Vector;
typedef Vector::iterator VectorItr;

class Solution {
public:

    Interval mergeIntervals(Interval a, Interval b){
    
        int minStart = min(a.start, b.start);
        int maxEnd = max(a.end, b.end);
        
        Interval merged = Interval(minStart, maxEnd);
        
        return merged;
    
    }

    bool overlap(Interval a, Interval b){
        
       
        
        bool answer = false;
        // Case 1: b.end lies in the middle of a
        if(a.start <= b.end && b.end <= a.end) answer = true;

        // Case 2: b.start lies in the middle of a
        if(a.start <= b.start && b.start <= a.end) answer =  true;
        
        // Case 3: b is larger than a, and encloses a in itself
        if(a.start >= b.start && a.end<= b.end) answer = true;
        
       
        return answer;
        
        
    }
    int lowerBoundBinSearch(Vector & intervals, Interval newInterval){
        
        int left = 0;
        int right = intervals.size()-1;
        
        int target = newInterval.start;
        
        
        while(left <= right){
            
            int mid  = left + (right-left)/2;
            int value = intervals[mid].start;
            
            
            if(target > value) left = mid + 1;
            else if(target < value) right = mid - 1;
            else if(target == value) return mid;
            
            
        }
        
        return right;
        
        
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        Vector answer;
        
        int index = lowerBoundBinSearch(intervals, newInterval);
        
        // If Intervals is Empty
        if(intervals.empty()) {
            
            answer.push_back(newInterval);
            return answer;
            
        }
        
        // Initializing the Answer
        answer.push_back(intervals[0]);
        
        int overlapDone = 0;
        
        for(int i = 0; i < intervals.size(); i++) {
            
            
            // Check Overlap with New Interval First
            Interval last = answer.back();
            
            if(overlapDone == 0 && overlap(last, newInterval)) {
                
                Interval merged = mergeIntervals(last, newInterval);
            
                answer.pop_back();
                answer.push_back(merged);
                overlapDone = 1;
                
            }
            
            // Check Overlap with last element in the Answer
            last = answer.back();
            if(overlap(last, intervals[i])){
                
                Interval merged = mergeIntervals(last, intervals[i]);
            
                answer.pop_back();
                answer.push_back(merged);
                
            }
            else answer.push_back(intervals[i]);
            
            
            
        }
        
        
        // If Overlap had to occur with the last element in the answer
        // if last element added in the last iteration
        Interval last = answer.back();
            
        if(overlapDone == 0 && overlap(last, newInterval)) {
                
                Interval merged = mergeIntervals(last, newInterval);
            
                answer.pop_back();
                answer.push_back(merged);
                overlapDone = 1;
                //i--;
        }
            
        
        // If overlap still not occured, insert the new Interval in the answer
        if(overlapDone == 0) {
            
            int index = lowerBoundBinSearch(answer, newInterval);
            //cout << "Index = " << index << endl;
            index++;
            VectorItr itr = answer.begin();
            itr = itr + index;
            
            answer.insert(itr, newInterval);
            
            
        }
        
        
        return answer;
    }
};