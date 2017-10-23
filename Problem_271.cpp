// Problem 271

using namespace std;

typedef vector<string> Vector;
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        
        string result = "";
        string at = "@@";
        
        for(int i = 0; i < strs.size(); i++){
            
            int length = strs[i].size();
            string begin = at + to_string(length) + at + strs[i];
            result = result + begin;
            
        }
        
        return result;
        
        
        
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        
        //cout << "Encoded String = " << s << endl << endl;
        
        Vector answer;
        string at = "@@";
        int found = -2;
        int next;
        
        do {
            
           found = s.find(at, found+2);
           next = s.find(at, found+2);
           
           //cout << "Found = " << found  << ", " << "Next = " << next << endl;
           
           if(next != -1 && found != -1){
               
                
                string numString = s.substr(found+2, next-found-2);
                //cout << "NumString = " << numString << endl;
                
                int num  = stoi(numString);
                
                string partial = s.substr(next + 2, num);
                //cout << "Partial = " << partial << endl;
                answer.push_back(partial);
                
                found = next + num;
                
           
           }
           
        }
        while(found < s.size() );
        
        return answer;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));