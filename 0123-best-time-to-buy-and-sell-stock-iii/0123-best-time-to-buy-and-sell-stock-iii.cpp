// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         if(n==0) return 0;
//         vector<vector<vector<int>>> dp(n,vector<int>(3,vector<int>(2,0)));
//         for(int i=n-1;i>=0;i--){ // index
//             for(int j=2;j>=0;j--){ // transactions left
//                 for(int k=1;k>=0;--){ // buy
//                     if(k==1){
//                         dp[i][j][k]=max(dp[i-1][j][k],d[i-1][j][0]-prices[i]);
//                     }
//                     else{
//                         dp[i][j][k]=max(dp[i-1][j][k],d[i-1][j-1][0]+prices[i]);
//                     }
//                 }
//             }
//         }
//         return dp[0][0][0];
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0) return 0;

        // dp[i][j][k]: max profit on day i, with j transactions left, and k = 1 (can buy) or 0 (can sell)
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(2, 0)));

        for(int i = n-1; i >= 0; --i) {
            for(int j = 1; j <= 2; ++j) {
                for(int k = 0; k <= 1; ++k) {
                    if(k == 1) { // Can buy
                        dp[i][j][k] = max(-prices[i] + dp[i+1][j][0], dp[i+1][j][1]);
                    } else {     // Can sell
                        dp[i][j][k] = max(prices[i] + dp[i+1][j-1][1], dp[i+1][j][0]);
                    }
                }
            }
        }

        return dp[0][2][1]; // Start at day 0, 2 transactions left, and can buy
    }
};
