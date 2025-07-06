class Solution {
    int recursion(int i,int prev,int prev_index,vector<int>& nums,vector<vector<int>>& dp){
        if(i<0) return 0;
        if(dp[i][prev_index] != -1) return dp[i][prev_index];
        if(nums[i]<prev){
            return dp[i][prev_index] =max(recursion(i-1,prev,prev_index,nums,dp),1+ recursion(i-1,nums[i],i,nums,dp));
        } 
        else return dp[i][prev_index] =recursion(i-1,prev,prev_index,nums,dp);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int prev=1e8;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return recursion(n-1,prev,n,nums,dp);
    }
};