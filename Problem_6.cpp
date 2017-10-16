// Problem 6

class Solution {
public:
    string convert(string s, int numRows) {
        
       
        string result="";
        
        if(numRows==1) return s;
        
        int step1,step2;
        int len=s.size();
        //cout << "Length  = " << len << endl;
        
        for(int i = 0; i < numRows; i++){
            
            step1 = (numRows - i - 1) * 2;
            step2 = i * 2;
            
           // cout << "Step 1 = " << step1 << " : " << "Step 2 = " << step2 << endl;
            int pos = i;
            if(pos < len) result = result + s[pos];
        
            while(1){
        
                pos = pos + step1;
                //cout << "S1 Pos = " << pos << endl;
                
                if(pos >= len)
                    break;
		
				if(step1)
					result = result  + s[pos];
				//	cout << "Result = " << result << endl;
        
        
        
                pos = pos + step2;
                //cout << "S2 Pos = " << pos << endl;
                
                if(pos >= len)
                    break;
                    
				if(step2)
					result = result + s[pos];
				
			//	cout << "Result = " << result << endl;
        
        
            }
        }
        
        return result;
        
    }
};