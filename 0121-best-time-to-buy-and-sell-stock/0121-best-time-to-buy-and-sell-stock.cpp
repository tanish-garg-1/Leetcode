class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int minn=prices[0];
        int sizee=prices.size();
        for(int i=0;i<sizee;i++){
            profit=max(profit,prices[i]-minn);
            minn=min(minn,prices[i]);
        }
        return profit;
    }
};