// Problem 435

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
using namespace std;

class Solution {
public:


    static bool compareFunc(Interval & a, Interval & b){
        
        // Increasing Sort based on second values of the Pair
        if(a.end < b.end) return true;
        else return false;
        
        
    }
    
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        
        
        
        sort(intervals.begin(), intervals.end(), compareFunc); // Increasing Sort based on second values of the Pair
       
        
        int remove = 0;
        if(intervals.empty()) return remove;
        
        int prevArrow = intervals[0].end;
        
        for(int i = 1; i < intervals.size(); i++){
            
           if(intervals[i].start < prevArrow) {
               remove++;
               continue;
               
           }
            
            prevArrow = intervals[i].end;
            
        }
        
        //cout << "Arrows = " << remove << endl;
        
        
       return remove;
        
    }
};