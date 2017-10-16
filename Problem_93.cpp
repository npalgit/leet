// Problem 93

using namespace std;

typedef vector<string> Vector;
typedef vector<int> IntVector;

class Solution {
public:

    void checkValidity(IntVector & currIP, int currLength, Vector & ans){
        
        string result = "";
        
        
        for(int i = 0; i < currIP.size(); i++ ) {
            
            int x = currIP[i];
            
           cout << x << "." ;
            
            if(x >= 0 && x <= 255) {  
            
                result = result + to_string(x);
                result = result + '.';
            }
            
            else return;
            
        }
        
       
        
        cout << "------  " << currLength; 
        cout << endl;
        
         result.erase(result.size()-1,1);
         ans.push_back(result);
        
    }
    
    void permuteIP(string remString, int remOctet, IntVector currIP, int currLength, int origLength, Vector & ans ){
        
       
        
        if((remOctet ==0) && (currLength == origLength )) {
            
            checkValidity(currIP, currLength, ans);
            return;
        }
        
        if((remOctet ==0) && (currLength  != origLength )) {
            
            return;
        }
        
        cout << "remString = " << remString << ": remOctet = " << remOctet  << endl;
        
         if(remString.empty()) return;
         
         
        string copyString = remString;
        IntVector copyIP = currIP;
        
        string currString= ""; 
        int currNum;
        
        int remDigits = remString.size();
        
        if(remDigits > 3*remOctet) return;
        
        else {
            
            
            for(int i = 1; i <=3; i++){
                
                
                currString = "";
                currString = remString.substr(0,i);
                
                if(currString.size() >1 && currString[0] == '0') return;
                
                currNum = stoi(currString);
                
                copyIP = currIP;
                
                copyIP.push_back(currNum);
                
                copyString = remString;
                copyString.erase(0,i);
                
                permuteIP(copyString, remOctet - 1, copyIP, currLength + i, origLength, ans);

            }
            
            
        }
        
    
        
    }
    vector<string> restoreIpAddresses(string s) {
        
        
        /*
        1. Again, this problem is all about corner cases.
        2. Do check the Solution in notes for this problem.
        3. Done in String Tag
        4. This question has majorly 7 corner cases
        
        
        
        
        */
        IntVector currIP;
        
        Vector ans;
        
        permuteIP(s, 4, currIP, 0, s.size(), ans);
        
        return ans;
        
    }
};