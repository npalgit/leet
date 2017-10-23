// Problem 315

using namespace std;

typedef pair<int, int> IntPair;
typedef vector<IntPair> Vector;
typedef Vector::iterator VectorItr;
typedef vector<int> IntVector;
//typedef pair<Vector, int> Pair;


class Solution {
public:

    
    
    void printVector(IntVector & nums){
        
        for(auto x : nums){
            
            cout << x << " : ";
        }
        cout << endl;
        
        
    }
    
    /*
    Pair countSplit(Vector B, Vector C) {
        
        //cout << "Inside Count Split " << endl;
        Vector D(B.size() + C.size(), 0);
        
        int bInd = 0; 
        int cInd = 0;
        
        int dInd = 0;
        
        int inv = 0;
        
        while(bInd <  B.size() && cInd <  C.size()) {
            
            // It is important to put elements from first array B in case of a tie
            // because then we don't increase the inversion count
            if(B[bInd] <= C[cInd]){
                
                D[dInd] = B[bInd];
                dInd++;
                bInd++;
                
            }
            
            else {
                
                D[dInd] = C[cInd];
                dInd++;
                cInd++;
                
                
                // If picking an element from 2nd array, increase inversions by number of remaining
                // elements to be sorted in the 1st array
                inv = inv + B.size() - bInd;
                
                
            }
            
            
        }
        
        while(bInd < B.size()) {
            
                D[dInd] = B[bInd];
                dInd++;
                bInd++;
            
        }
        
        while(cInd < C.size()) {
            
                D[dInd] = C[cInd];
                dInd++;
                cInd++;
            
        }
        
        return make_pair(D, inv);
        
        
    }
    
    Pair countInversions(Vector & nums, int low, int high) {
        
        if(low == high) {
            
            Vector temp;
            temp.push_back(nums[low]);
            
            return make_pair(temp, 0);
            
        }
        
        int mid = low + (high - low)/2;
        
        Pair left = countInversions(nums, low, mid);
        Pair right = countInversions(nums, mid+1, high);
        
        
        Pair countPair = countSplit(left.first, right.first);
        
        int totalInv = left.second + right.second + countPair.second; 
        
        return make_pair(countPair.first, totalInv);
        
        
    }
    
    */
    
    
    
    Vector countSplit(Vector B, Vector C, IntVector & result) {
        
        //cout << "Inside Count Split " << endl;
        Vector D(B.size() + C.size(), {0,0});
        
        int bInd = 0; 
        int cInd = 0;
        
        int dInd = 0;
        
        int inv = 0;
        
        while(bInd <  B.size() && cInd <  C.size()) {
            
            // It is important to put elements from first array B in case of a tie
            // because then we don't increase the inversion count
            
            
            // If picking an element from First Array, then numbers from Second Array that have already been merged,
            // are the numbers that are smaller than the present element in the second Array.
            if(B[bInd] <= C[cInd]){
                
                D[dInd].first = B[bInd].first;
                D[dInd].second = B[bInd].second;
                
                int index = B[bInd].second;
                result[index] = result[index] + cInd;
                
                dInd++;
                bInd++;
                
                
                
            }
            
            else {
                
                D[dInd].first = C[cInd].first;
                D[dInd].second = C[cInd].second;
                
                dInd++;
                cInd++;
                
                
            }
            
            
        }
        
        while(bInd < B.size()) {
            
                D[dInd].first = B[bInd].first;
                D[dInd].second = B[bInd].second;
                
                int index = B[bInd].second;
                result[index] = result[index] + cInd;
                
                dInd++;
                bInd++;
                
                
                
            
        }
        
        while(cInd < C.size()) {
            
                D[dInd].first = C[cInd].first;
                D[dInd].second = C[cInd].second;
                
                dInd++;
                cInd++;
                
            
        }
        
        return D;
        
        
    }
    
    Vector countInversions(IntVector & nums, IntVector & result, int low, int high) {
        
        if(low == high) {
            
            Vector temp;
            temp.push_back({nums[low], low});
            
            return temp;
            
        }
        
        int mid = low + (high - low)/2;
        
        Vector left = countInversions(nums, result, low, mid);
        Vector right = countInversions(nums, result, mid+1, high);
        
        
        Vector countPair = countSplit(left, right, result);
        
        //int totalInv = left.second + right.second + countPair.second; 
        
        return countPair;
        
        
    }
    
    
    
    
    
    
    vector<int> countSmaller(vector<int>& nums) {
        
        
        IntVector answer(nums.size(), 0);
        
        if(nums.size() < 2) return answer;
        
        Vector result = countInversions(nums, answer, 0, nums.size()-1);
        
        //cout << "Inversions = " << result.second << endl;
        
        
        return answer;
        
        
        
        
        
    }
};