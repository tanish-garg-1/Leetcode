class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++){
            profit=max(profit,prices[i]-prev);
            prev=min(prev,prices[i]);
        }
        return profit;
    }
};