// Problem 321


using namespace std;

typedef vector<int> Vector;

class Solution {
public:

    Vector giveVectorKeep(Vector myVect, int keep){
        
        if(keep == 0){
            
            myVect.clear();
            return myVect;
            
        }
        // Returns a vector of size keep, and it keeps the digits which form the MAXIMUM number
        while(myVect.size() > keep){
            
            int size = myVect.size();
            int i;
            for(i = 0; i < size-1; i++){
                
                
                if(myVect[i] < myVect[i+1]){
                    
                    myVect.erase(myVect.begin() + i);
                    break;
                    
                }
        
            }
            
            if(i == size-1) myVect.erase(myVect.begin() + i);
        }
        
        return myVect;
        
    }
    

    Vector mergeVectors(Vector & nums1, Vector & nums2){
        
        int k = nums1.size() + nums2.size();
        Vector result(k, 0);
        int i = 0, j = 0;
        
        for (int r = 0; r < k; r++) {
            
            result[r] = compareVectors(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
            
        }

        return result;
    
    }
    
    bool compareVectors(Vector &finalResult, int i, Vector result, int j){
        
        
        
        // True means keeping the Final Vector
        // False means Replacing the Final Vector with thr Current Vector
        
        while(i < finalResult.size() && j < result.size() && finalResult[i] == result[j]){
            
            i++;
            j++;
            
        }
        
        if(j == result.size()) return true;
        if(i < finalResult.size() && finalResult[i] > result[j]) return true;
        else return false;
        
        
        return false;
        
        
    }
    
    void printVector(Vector & myVect){
        
        
        for(auto x : myVect){
            
            cout << x << " : "; 
        }
        
        cout << endl;
        
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        
        Vector answer;
        if(k > nums1.size() + nums2.size()) return answer;
        
        if(nums1.empty()) return giveVectorKeep(nums2, k);
        if(nums2.empty()) return giveVectorKeep(nums1, k);
        
        Vector finalResult;
        
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        
        for(int i =  max(0, k - nums2Size); i <= min(k, nums1Size); i++){
            
          
            Vector nums1Result = giveVectorKeep(nums1, i);
           
            Vector nums2Result = giveVectorKeep(nums2, k-i);
            
            
            Vector result = mergeVectors(nums1Result, nums2Result);
            
            
            if (compareVectors(result, 0, finalResult, 0)) finalResult = result;

            
        }
        
        
        
        return finalResult;
        
        
    }
};