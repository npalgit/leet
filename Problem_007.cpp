// Problem 7

using namespace std;

class Solution {
public:

    void reverseString(string & str) {
        
        int left = 0; int right = str.size()-1;
        
        while(left < right) {
            
            char temp = str[left];
            
            str[left] = str[right];
            str[right] = temp;
            
            left++;
            right--;
            
            
        }
        
    }
    int reverse(int x) {
        
        /*
        1. Only some detail required to deal with the corner cases
        2. Rest, it is an easy problem
        
        
        */
        string str = to_string(x);
        int sign = 1;
        
        if(str[0] == '-') {
            sign = -1;
            str.erase(0,1);
        
        }
        reverseString(str);
        
        while(str.size() && str[0] == '0') str.erase(0,1);
        
        int answer;
        
        
        try{
            
            answer = stoi(str);
        }
        
        catch(...){
            
            answer = 0;
        }
        
        answer = answer * sign;
        return answer;
        
     
        
    }
};