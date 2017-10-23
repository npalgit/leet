// Problem 89

#include<biset>

typedef vector<string> Vector;
typedef Vector::iterator VectorItr;
typedef Vector::reverse_iterator VectorRItr;
typedef vector<int> intVector;


class Solution {

public:


    void dispVector(Vector & myVect){

    int size = myVect.size();

    for(int i = 0; i < size; i++){

        cout << myVect[i] <<" -- ";
    }

    }
    Vector reverseVector(Vector& myVect){
        
        Vector copyVect;
        VectorRItr itr = myVect.rbegin();
        while(itr!= myVect.rend()){
            
            copyVect.push_back("1" + *(itr));
            itr++;
        }
        
        return copyVect;
        
    }
    
    Vector addZero(Vector& myVect){
        
        VectorItr itr = myVect.begin();
        while(itr != myVect.end()){
            *itr = "0" + *itr;
            itr++;
        }
        
        return myVect;
    }
    
    
    vector<int> grayCode(int n)
    {
        
        /*
        intVector grayVector;
        Vector myVect;
        Vector copyVect;
        
        myVect.push_back("0");
        if(n==0){
            grayVector.push_back(0);
            return grayVector;
        };
        myVect.push_back("1");
        
        
 

  
        
        for(int i = 2; i<= n; i++ ){
            
            copyVect = reverseVector(myVect);
          //  cout << "Vector is reversed" << endl;
            myVect = addZero(myVect);
           // cout << "Vector is zero added" << endl;
            
            myVect.insert(myVect.end(), copyVect.begin(), copyVect.end());
            
        }

        
        //dispVector(myVect);
        


        for(int j = 0; j < myVect.size(); j++){
            
            
            int intValue = stoi(myVect[j], nullptr, 2);
            grayVector.push_back(intValue);
        }
        
        return grayVector;


        */
        
        
        int N = 1<<n ;
        int temp;
        
        intVector result;
        
        
        for(int i = 0; i < N; i++){
            
            temp = i << 1;
            int answer = temp ^ i;
            answer = answer >> 1;
            
            result.push_back(answer);
        }
        
        
        return result;
        
    }
};