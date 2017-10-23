// Problem 253

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
 typedef vector<int> IntVector;
 
 
 bool compare(Interval a, Interval b){
     
     if(a.start < b.start) return true;
     else return false;
     
 }
 
 bool conflict(Interval a, Interval b){
     
     if(a.start == b.start && a.end == b.end) return true;
     if(b.start < a.end) return true;
     else return false;
     
 }
 
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        int rooms = 0;
        int meetingCount = 0;
        
        // Increasing Sort based on the Starting Times
        sort(intervals.begin(), intervals.end(), compare);
        
        // Table to check if a meeting has been allotted room or not
        IntVector table(intervals.size(), 0);
        
        // Greedy Loop = will keep on running until all meetings are alloted rooms
        while(meetingCount < intervals.size()){
            
            Interval lastBook(0,0);
            
            // Loop for the current room
            // Allocate every possible non-conflicting meeting to this room
            for(int i = 0; i < intervals.size(); i++){
                
                // if room already alloted to this meeting, continue
                if(table[i] != 0) continue;
                else {
                    
                    
                    Interval currInterval = intervals[i];
                    
                    // Update the Last booked meeting in this room
                    if(lastBook.start == 0 && lastBook.end == 0){
                        
                        meetingCount++;
                        lastBook = currInterval;
                        table[i] = 1;
                        
                        continue;
                        
                    }
                    
                    // Check conflict of last booked meeting in this room with current meeting
                    // If no conflict, allocate meeting to this particular room
                    if(!conflict(lastBook, currInterval)) {
                        
                        meetingCount++;
                        lastBook = currInterval;
                        table[i] = 1;
                        
                        
                    }
                    
                }
            
            }
            
            rooms++;
        }
        
        return rooms;
    }
};