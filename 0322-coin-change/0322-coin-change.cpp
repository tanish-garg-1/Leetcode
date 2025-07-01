class Solution {
    int recursion(int i,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(amount==0) return 0;
        if(i<0 || amount<0) return 1e9;
        if(dp[i][amount] != -1) return dp[i][amount];
        int left=recursion(i,amount-coins[i],coins,dp)+1;
        int right=recursion(i-1,amount,coins,dp);
        return dp[i][amount]=min(left,right);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int result = recursion(n-1,amount,coins,dp);
        if(result==1e9) return -1;
        else return result;
    }
};