// Problem 91

using namespace std;


typedef vector<int> Vector;

class Solution {
public:
    int numDecodings(string s) {
    
    
        if(s.empty()) return 0;
        
    
        
        //if( s[s.size()-1] == '0' &&  stoi(s.substr(s.size()-2, 2)) >= 30 ) return 0;
        
        Vector myVect;
        int num0= s[0] - '0';
        
        
        int init = 0;
        //myVect.push_back(0);
        
        if(num0 >=1 && num0 <= 9) init = 1;
        myVect.push_back(init);
        
        if(s.size() > 1){
            
            int num1 = s[1] - '0';
            int num01 = num0*10 + num1;
            
            
            init = 0;
            //init = myVect[myVect.size()-1];
            if(num1 >= 1 && num1 <= 9) init = myVect[myVect.size()-1];
            if(num01 >= 10 && num01<= 26) init++;
            
          
            myVect.push_back(init);
        }
        
        int backNum, currNum;
        string back = "";
        int currSize;
        string temp;
        
        
        for(int i = 2; i < s.size(); i++){
            
            //back.clear();
            
         //  cout << s[i-1] <<s[i] <<  endl;
         //  cout << to_string(s[i-1] - '0') + to_string(s[i] - '0') <<  endl;
            
            back = to_string(s[i-1] - '0') + to_string(s[i] - '0');
            
           
            
        //  cout << "Back String = " << back <<  endl;
            backNum = stoi(back);
            temp = s[i];
            currNum = stoi(temp);
            int temp=0;
            if(currNum >= 1 && currNum <= 9) temp+=myVect[myVect.size()-1];
            
            if(backNum >= 10 && backNum <= 26) temp+= myVect[myVect.size()-2];
            
           
            
            myVect.push_back(temp);
            
        }
        
        
       // for(auto x: myVect) cout << x << " : " ;
       // cout << endl;
         //if(myVect.size() > 4) myVect.erase(myVect.begin());
        
        return myVect[myVect.size()-1];
        
        
        
    
       
        /*
        if(s.empty()) return 0;
        if(s[0] == '0') return 0;
        if(s.size() == 1) return 1;
        
        //if( s[s.size()-1] == '0' &&  stoi(s.substr(s.size()-2, 2)) >= 30 ) return 0;
        
        Vector myVect;
        myVect.push_back(1);
        myVect.push_back(1);
        
        int backNum;
        string back = "";
        int currSize;
        
        
        
        for(int i = 1; i < s.size(); i++){
            
            //back.clear();
            
         //  cout << s[i-1] <<s[i] <<  endl;
         //  cout << to_string(s[i-1] - '0') + to_string(s[i] - '0') <<  endl;
            
            back = to_string(s[i-1] - '0') + to_string(s[i] - '0');
            
           
            
        //  cout << "Back String = " << back <<  endl;
            backNum = stoi(back);
            
            if(back == "00") return 0;
             if(back[1] == '0' && (backNum != 10 || backNum != 20)) return 0;
            
         // cout << "Back Num  " << backNum  << endl;
            currSize = myVect.size();
            
            if( (backNum < 27) && (backNum%10 != 0) &&  backNum > 9) myVect.push_back(myVect[currSize-1] + myVect[currSize-2]);
            else if(backNum%10 == 0) myVect.push_back(myVect[currSize-2]);
            else myVect.push_back(myVect[currSize-1]);
            
            if(myVect.size() > 4) myVect.erase(myVect.begin());
            
           // for(auto x: myVect) cout << x << " : " ;
          // cout << endl;
            
        }
        
        
        
        //cout << "Out of all loops" << endl;
        
        return myVect[myVect.size()-1];
        
        */
    }
};