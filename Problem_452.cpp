// Problem 452


using namespace std;

typedef pair<int, int> Pair;
typedef vector<Pair> Vector;

class Solution {
public:

    void printVector(Vector & myVect){
        
        for( auto x : myVect){
            cout << x.first << " , " << x.second << " :::: " ;
            //cout << x << " : ";
        }
        
        cout << endl;
        
    }
    
    static bool compareFunc(Pair & a, Pair & b){
        
        // Increasing Sort based on second values of the Pair
        if(a.second < b.second) return true;
        else return false;
        
        
    }
    
 
    int findMinArrowShots(vector<pair<int, int>>& points) {
        
        /*
        
        1. Very simple Solution
        2. The key thing is to notice that we have to sort the intervals based on their second values.
        3. Afterwards, it is simple logic.
        4. No Corner Cases as well.
        
        
        
        */
        
        
        
        //printVector(points);
        sort(points.begin(), points.end(), compareFunc); // Increasing Sort based on second values of the Pair
        //printVector(points);
        
        int arrows = 0;
        int prevArrow = INT_MAX;
        
        for(auto point : points){
            
            if(arrows == 0 || point.first > prevArrow ) {
                
                arrows++;
                prevArrow = point.second;
            }
            
        }
        
        return arrows;
    }
};