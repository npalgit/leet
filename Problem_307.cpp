// Problem 307


using namespace std;

typedef vector<int> Vector;

class NumArray {
    
private:

    Vector fenwickTreeArray;
    Vector numsArray;
    
public:

    int getRightMostSetBitNumber( int orig){
        
        int neg = ~orig;
        int twoComp = neg + 1;
        
        int result = twoComp & orig;
        
        return result;
        
    }
    
    int getParent(int orig){
        
        int temp = getRightMostSetBitNumber(orig);
        return orig - temp;
        
    }
    
    int getNext(int orig){
        
        int temp = getRightMostSetBitNumber(orig);
        return orig + temp;
        
    }
    
    void printVector(Vector & myVect){
        
        for(auto x: myVect){
            
            cout << x << " : ";
            
        }
        cout << endl;
        
    }
    
    NumArray(vector<int> nums) 
    {
        numsArray = nums;
        fenwickTreeArray.resize(nums.size()+1, 0);
        
        int fenwickSize = fenwickTreeArray.size();
        
        for(int i = 0; i < nums.size(); i++){
            
            int next = i+1;
             
            while(next < fenwickSize){
                
                fenwickTreeArray[next] += nums[i]; 
                next = getNext(next);
                
                
            }
            
            
            
        }
        
        //printVector(fenwickTreeArray);
        
        
        
    }
    
    void update(int i, int val) {
        
        int original = numsArray[i];
        
        int delta = val - original;
        
        int next = i+1;
        int fenwickSize = fenwickTreeArray.size();
             
        while(next < fenwickSize){
                
            fenwickTreeArray[next] += delta; 
            next = getNext(next);
                
                
        }
        
        numsArray[i] = val;
        
    }
    
    int sumRange(int i, int j) {
        
        int sumI=0, sumJ=0;
        int parentI = i, parentJ = j + 1;
        
        while(parentJ != 0){
            
            sumJ = sumJ + fenwickTreeArray[parentJ];
            parentJ = getParent(parentJ);
            //cout << "Parent J = " << parentJ << endl;
            
        }
        
        //cout << "After Sum J = " << sumJ << endl;
        
        while(parentI != 0){
            
            sumI = sumI + fenwickTreeArray[parentI];
            parentI = getParent(parentI);
            //cout << "Parent I = " << parentI << endl;
            
        }
        
        return sumJ - sumI;
        
         
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */