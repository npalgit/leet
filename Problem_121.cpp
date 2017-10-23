// Problem 121

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        /*
        1. Just maximize what you want to maximize by keeping it simple.
        
        
        */
        
        int minPrice = INT_MAX; int maxProfit = 0;
        
        for(int i = 0; i < prices.size(); i++){
            
            
            minPrice = min(minPrice, prices[i]);
            
            int currProfit = prices[i] - minPrice;
            maxProfit = max(maxProfit, currProfit);
            
            //cout << "Min Price = " << minPrice << ": Max Profit = " << maxProfit << endl;
        }
        
        return maxProfit;
        
        
    }
};