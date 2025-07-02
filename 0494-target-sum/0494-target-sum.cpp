class Solution {
    int recursion(int i,int target,vector<int>& nums,vector<vector<int>>& dp){
        if(target==0 && i<0) return 1;
        if(i<0) return 0;
        if(dp[i][target+10000] != -1) return dp[i][target+10000];
        int left=recursion(i-1,target-nums[i],nums,dp);
        int right=recursion(i-1,target+nums[i],nums,dp);
        return dp[i][target+10000]=left+right;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(20001,-1));
        return recursion(n-1,target,nums,dp);
    }
};