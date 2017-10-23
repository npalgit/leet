// Problem 281


using namespace std;

typedef vector<int> Vector;
typedef Vector::iterator VectItr;

class ZigzagIterator {
    
    /*
    
    1. It is a good problem that deals with Corner Cases
    2. Concept of Iterators is very convenient as it helps in initializing pointers and advancing them
    3. Dealing with a case when any of the vectors is empty is most important
    4. Solved in DESIGN
    
    */
    
private:
    
    VectItr beginItr[2], endItr[2];
    int lastElem;
    
public:

    ZigzagIterator(vector<int>& v1, vector<int>& v2)
    {
        
        //cout << "Total Elements = " << totalElems << endl;
        
        beginItr[0] = v1.begin();
        beginItr[1] = v2.begin();
        
        endItr[0] = v1.end();
        endItr[1] = v2.end();
        
        lastElem = 0;
        if(v1.size() != 0 && v2.size() == 0) lastElem = 0;
        if(v1.size() == 0 && v2.size() != 0) lastElem = 1;
        
        cout << "Last Element  =  " << lastElem  << endl;
        
        
        
    }

    int next() {
        
        int elem;
        //lastElem = (lastElem + 1) % 2;
        
        if(lastElem == 0 && beginItr[0] != endItr[0]) {
            
            elem = *(beginItr[0]);
            beginItr[0]++;
        }
        
        if(lastElem && beginItr[1] != endItr[1]) {
            
            elem = *(beginItr[1]);
            beginItr[1]++;
            
        }
        
        
        if(beginItr[0] != endItr[0] && beginItr[1] != endItr[1]) {
            
            lastElem = (lastElem + 1) % 2;
        
        }
        
        if(beginItr[0] == endItr[0]) lastElem = 1;
        if(beginItr[1] == endItr[1]) lastElem = 0;
        
       // cout << "Elem = " << elem << endl;
        return elem;
        
    
    }

    bool hasNext() {
        
        if(beginItr[0] != endItr[0] || beginItr[1] != endItr[1]) {
        
            //cout << "True" << endl;
            return true;
        }
        
        else {
         
           // cout << "False " << endl;   
            return false;
        }
       
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */