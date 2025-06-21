class Solution {
    int calc(int i,int n,vector<int>& dp){
        if(i>n) return 0;
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=calc(i+1,n,dp)+calc(i+2,n,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return calc(0,n,dp);
    }
};

// class Solution {
//     void calc(int sum,int &sol,int &n){
//         if(sum>=n){
//             if(n==sum) sol=sol+1;
//             return;
//         }
//         calc(sum+1,sol,n);
//         calc(sum+2,sol,n);
//         return;
//     }
// public:
//     int climbStairs(int n) {
//         int sol=0,sum=0;
//         calc(sum,sol,n);
//         return sol;
//     }
// };