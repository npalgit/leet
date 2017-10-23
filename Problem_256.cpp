// Problem 256

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
       if(costs.size() == 0) return 0;
        
        int houses = costs.size();
        
        cout << "Houses = " << houses << endl;
        
        for(int i = 1; i < costs.size(); i++){
            
            costs[i][0] =  costs[i][0] + min(costs[i-1][1] , costs[i-1][2]);
            
            costs[i][1] =  costs[i][1] + min(costs[i-1][0] , costs[i-1][2]);
            
            costs[i][2] =  costs[i][2] + min(costs[i-1][0] , costs[i-1][1]);
            
            
            
        }
        
        int finalCosts = min(costs[houses-1][0], min(costs[houses-1][1], costs[houses-1][2]));
        //int finalCosts = 0;
        
        return finalCosts;
        
    }
};