// Problem 354

using namespace std;

typedef pair<int, int> Pair;
typedef vector<Pair> Vector;
typedef Vector::iterator VectorItr;


bool comparator(Pair a, Pair b){
        
        // If First elements same, Decreasing Sort for Second Elements
        if(a.first == b.first) return a.second > b.second;
        
        // Else, Increasing Sort for First Elements
        else return a.first < b.first;
        
}
    
class Solution {
public:

    
    
    void printVector(Vector & myVect){
        
        for(auto x : myVect){
            
            cout << x.first << ", " << x.second << " : "; 
            
        }
        
        cout << endl;
        
        
    }
    
    int upperBoundBinSearch(Vector & table, Pair currPair) {
        
        
        int left = 0;
        int right = table.size()-1;
        
        while(left <= right){
            
            int mid = left + (right-left)/2;
            
            Pair midPair = table[mid];

            if(currPair.second > midPair.second ) left = mid + 1;
            else right = mid - 1;
            
            
        }
        
        return left;
        
        
        
    }
    
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        
        
        //printVector(envelopes);
        sort(envelopes.begin(), envelopes.end(), comparator);
        //printVector(envelopes);
        

        if(envelopes.size() < 2) return envelopes.size();
        
        Vector table;
        
        for(auto x : envelopes){
            
            
            int index = upperBoundBinSearch(table, x);
            
            if(index == table.size()) table.push_back(x);
            else table[index] = x;
            
            //cout << "Index = " << index << endl;
            //printVector(table);
            //cout << endl;
            
            
        }
        
        return table.size();
        
    }
};