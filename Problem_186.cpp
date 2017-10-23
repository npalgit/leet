// Problem 186

using namespace std;


class Solution {
public:
    void reverseString(string &s, int start, int end){
        
        while(start < end){
            
            char begin = s[start];
            s[start] = s[end];
            s[end] = begin;
            
            start++;
            end--;
            
            
        }
        
        
    }
    void reverseWords(string &s) {
        
        //cout << s << endl;
        reverseString(s, 0, s.size()-1);
        
        int start = 0;
        int end = 0;
        
        do{
            
            end = s.find(" ", start);
            if(end != -1)reverseString(s, start, end-1);
            
            if(end != -1)start = end + 1;
            
            
        }
        while(end != -1);
        
        reverseString(s, start, s.size()-1 );
        
        //cout << s;
        
    }
};