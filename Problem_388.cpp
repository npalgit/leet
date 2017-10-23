// Problem 388

using namespace std;

typedef vector<int> Vector;

class Solution {
public:

    void replaceAll(string & input, string repMent, string elem){
        
        
         int index = -1;
         
         do{
           
           index++;
           index = input.find(elem, index);
           
           
           if(index != -1)input.replace(index, 1, repMent);
           
       }
        while(index != -1) ;
        
        
    }
    
    
    int lengthLongestPath(string input) {

       /*
       1. Very easy question
       2. You should just focus on how it is organized.
       3. Number of Tabs tell the level
       4. It is required to replace tabs with something else to avoid cout problems.
       5. Solved in STRING
       
       
       
       */
       
       
        string repMent1 = "~";
        string repMent2 =  "#";
        
        string newLine = "\n";
        replaceAll(input, repMent1, newLine);
        
        string newTab = "\t";
        replaceAll(input, repMent2, newTab);
        
       
        
        cout << "Input = " << input << endl;
        
        
        stringstream ss;
        
        ss.str(input);
        string midPath;
        
        Vector myVect(20,0);
        int maxLength = 0;
        
        int level = 0;
        
        char delim = '~';
        while(getline(ss, midPath, delim)){
            
            //cout << "MidPath  = " << midPath << endl;
            
            // Always calculating the level assuming it starts from zero
            level = 0;
            
            // Calculate the level here
            while(midPath[0] == '#') {
                
                midPath.erase(0,1);
                level++;
            }
            
            int midPathSize = midPath.size();
            
            
            
            //cout << "Level = " << level << endl;
            
            // Doing Cumsum to avoid doing the sum from starting all over again
            myVect[level+1] = myVect[level] + midPathSize + 1;
            
            
            // -1 subtracted to remove the last slash
            if(midPath.find('.') != -1) maxLength  = max(maxLength, myVect[level+1]-1);
            
        }
        
        //for(auto x : myVect) cout << x << " : " ;
       // cout << endl;
        
       // cout << "Modified Input = " << input << endl;
        
        return maxLength;
    
    
 
    
    }
};