// Problem 151

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
    void reverseWords2(string &s) {
        
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
    
    
  void trimWhiteSpace(string & str){
      
      //if(str.empty()) return;

      while(str.size() && str[0] == ' ') str.erase(0,1);
      
      //if(str.empty()) return;

      while(str.size() && str[str.size()-1] == ' ') str.erase(str.size()-1,1);

  }


  void replaceMultipleSpaces(string & str){


      if(str.empty() ) return;

      string space = " ";
      int start = 0;
      int end  = 0;

      do{

        	while(end < str.size() && isspace(str[end]) == 0) end++;
        
        	//cout << "End = " <<  str[end] <<  " : " << end << endl;
        
        	start = end;
              
        	while(start < str.size() && isspace(str[start])) str.erase(start, 1);
        
        
        	str.insert(start, space);
        	
        
        	end = start + 1;

      }
      while(end < str.size());


  }
    
    
    void reverseWords(string &s) {
        
        trimWhiteSpace(s);
        cout << "After Trimming = " << s <<endl;
        //reverseString(s, 0, s.size()-1);
        
        //cout <<"After Reverse = " << s << endl;
        replaceMultipleSpaces(s);
        
        
        cout <<"After Multiple Spaces = " << s << endl;
        
        reverseWords2(s);
        
        trimWhiteSpace(s);
        
        
       
        
        
        
        
        
        
    }
};