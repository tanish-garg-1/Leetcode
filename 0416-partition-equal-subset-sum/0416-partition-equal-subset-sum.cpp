class Solution {
    bool recursion(int i,int half,vector<int>& nums,vector<vector<int>>& dp){
        if(half==0) return true;
        if(i<0 || half<0) return false;
        if(half>=0 && dp[i][half]!=-1) return dp[i][half];
        bool take=recursion(i-1,half-nums[i],nums,dp);
        bool not_take=recursion(i-1,half,nums,dp);
        return dp[i][half]=take || not_take;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int half=0;
        for(int i=0;i<n;i++) half=half+nums[i];
        if(half%2==1) return false;
        else half=half/2;
        vector<vector<int>> dp(n,vector<int>(half+1,-1));

        return recursion(n-1,half,nums,dp);
    }
};


// class Solution {
//     bool recursion(int i,int l,int r,vector<int>& nums,vector<vector<int>>& dp){
//         if(i==-1) return left==right;
//         if(dp[l][r]!=-1) return dp[l][r]; 
//         if(recursion(i-1,nums[i]+l,r,nums,dp) || recursion(i-1,l,nums[i]+r,nums,dp)) return true;
//         return false;
//     }
// public:
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(100*n+1,vector<int>(100*n+1,-1));
//         return recursion(n-1,0,0,nums,dp);
//     }
// };