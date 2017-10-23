// Problem 90

using namespace std;


typedef vector<int> Vector;
typedef vector<Vector> Matrix;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
       /*
       1. Complex problem
       2. Solved in ARRAY
       3. Methodology is very important. See the notes
       
       
       */
        
        
        Matrix table ;
        Vector blank;
        
        table.push_back(blank);
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        int count = 0;
        
        while(i < nums.size()){
            
            //cout << "********************" << endl;
            count = 0;
            while((i + count) < nums.size() && (nums[count + i] == nums[i])) count++;
            //cout << "Count  = " << count << endl; 
            
            
           int previousN = table.size();
           //cout << "Previous Table Size = " << previousN << endl;
            
            for(int k = 0;  k < previousN; k++){
                
                
                Vector instance = table[k];
                
                
                for(int j = 0; j < count ; j++){
                    
                    instance.push_back(nums[i]);
                    table.push_back(instance);
                }
                
                /*
                cout << endl << "Table Starts " << endl ;
                for(auto x: table) {
                    
                    cout << "[";
                    for(auto y : x) cout << y << ",";
                    cout << "], ";
                }
                cout << endl;
                */
                
                instance.clear();
            }
            
            
            
            i = i + count;
        }
        
        return table;
        
        
    }
};