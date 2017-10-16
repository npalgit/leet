// Problem 12

typedef vector<string> Vector;

class Solution {
public:
    string intToRoman(int num) {
        
        /*
        
        1. This question is easy only if you use the modified table
        2. Dont use the original table
        3. See it in STRING
        4. Afterwads, simple solution, and an iterative process
        
        
        */
        string result = "";
        string partial = "";
        if(num == 0) return result;
        
       
        //for(auto x : table) cout << ": " << x;
        //cout << endl;
        
        
        int arr[13] =      {1,     4,   5,    9,   10,  40,   50,  90,   100, 400, 500, 900, 1000};
        string table[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        
        int remder = num;
        int quo = 0;
        
        while(remder){
            
            for(int i = 12; i >=0; i--){
                
                partial = "";
                
                if(remder >= arr[i]){
                    
                    quo = remder / arr[i];
                    remder = remder%arr[i];
                    
                    while(quo){
                        
                        partial = partial + table[i];
                    
                        quo--;
                    }
                    
                    result = result + partial;
                    continue;
                }
                
                
            }
            
            
        }
        
        
        
        return result;
        
    }
};