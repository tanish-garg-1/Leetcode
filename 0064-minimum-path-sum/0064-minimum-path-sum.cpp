class Solution {
    int recursion(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int top=recursion(i-1,j,grid,dp);
        int left=recursion(i,j-1,grid,dp);
        return dp[i][j]=grid[i][j]+min(top,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return recursion(m-1,n-1,grid,dp);
    }
};