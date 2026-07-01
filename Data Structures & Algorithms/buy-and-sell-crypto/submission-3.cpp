class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minprice=prices[0];
        int maxprofit=0;
        for(int i=0;i<n;i++){
            minprice=min(prices[i],minprice);
            int curr_profit=prices[i]-minprice;
            maxprofit=max(maxprofit,curr_profit);
                
        }
        return maxprofit;
        
    }
};
