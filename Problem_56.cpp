// Problem 56

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
 
 
 bool compare(Interval a, Interval b){
     
     if(a.start < b.start) return true;
     else return false;
     
 }
 
 bool conflict(Interval a, Interval b){
     
     if(b.start <= a.end) return true;
     else return false;
     
 }
 
Interval mergeIntervals(Interval a, Interval b){
    
    int minStart = min(a.start, b.start);
    int maxEnd = max(a.end, b.end);
    
    Interval merged = Interval(minStart, maxEnd);
    
    return merged;
    
}
 
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        Vector answer;
        if(intervals.empty()) return answer;
        
        
        sort(intervals.begin(), intervals.end(), compare);
        
        
        answer.push_back(intervals[0]);
        
        
        for(int i = 1; i < intervals.size(); i++){
            
            Interval last = answer.back();
            
            if(conflict(last, intervals[i])){
                
                Interval merged = mergeIntervals(last, intervals[i]);
                answer.pop_back();
                
                answer.push_back(merged);
                
                
                
            }
            
            else answer.push_back(intervals[i]);
            
            
        }
        
        return answer;
        
        
    }
};