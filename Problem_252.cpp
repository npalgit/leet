// Problem 252

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 
 typedef vector<int> Vector;
 
 bool compare(Interval a, Interval b){
     
     if(a.start <= b.start) return true;
     else return false;
     
     
 }
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);
        
        for(int i = 1; i < intervals.size(); i++) {
            
            if(intervals[i].start >= intervals[i-1].end) continue;
            else return false;
            
            
        }
        
        
        return true;
    }
};