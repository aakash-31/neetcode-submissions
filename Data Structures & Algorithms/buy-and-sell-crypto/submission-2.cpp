class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        int buy=0;
        int sell=1;
        while(sell<n){
            if(prices[buy]>prices[sell]){
                buy=sell;
            }
            else{
                profit=max(profit,prices[sell]-prices[buy]);
            }
        sell++;
        }
        
        return profit;
    }
};
