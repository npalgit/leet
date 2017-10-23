// Problem 312


using namespace std;

typedef pair<int, int> Pair;
typedef vector<int> Vector;
typedef vector<Vector> Matrix;


class Solution {
public:

    void printTable(Matrix & table){
        
        
        //setw(3);
        
        for(auto x : table){
            
            for(auto y : x){
                
                cout << setfill('0') << setw(3) <<y << " : ";
                
            }
            cout << endl;
            
        }
        
        cout <<endl << endl;
        
    }
    
    int maxCoins(vector<int>& nums) {
        
       
        
        int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        
        
        Vector row(nums.size(), 0);
        Matrix table(nums.size(), row);
        
        
        for(int len = 1; len <= N; len++){
            
            for(int start = 1; start <= N - len + 1; start++){
                
                
                int end  = start + len - 1;
                
                //cout << "Start = " << start << ", End = " << end << ", Len = " << len << endl;
                
                
                int bestCoins = 0;
                
                for(int last = start; last <= end; last++){
                    
                    //cout << endl << "Last = " << last << endl;
                    int back = table[start][last-1] + table[last+1][end];
                    
                    int current = nums[start-1] * nums[last] * nums[end+1];
                    
                    int coins = back + current;
                    
                    //cout << "Back = " << back << ", Current = " << current << endl;
                    bestCoins = max(bestCoins, coins);
                    
                    //cout << "Coins = " << coins << ", BestCoins = " << bestCoins << endl;
                    
                    
                }
                
                table[start][end] = bestCoins;
                //printTable(table);
                
            }
            
            
            
            
        }
        
        return table[1][N];
        
    }
};