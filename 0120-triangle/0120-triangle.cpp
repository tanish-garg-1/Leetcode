class Solution {
    int recursion(int row,int col,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(row==triangle.size()) return 0;
        if(col<0 || col>row) return INT_MAX;
        if(dp[row][col]!=-1) return dp[row][col];
        int left=recursion(row+1,col,triangle,dp);
        int right=recursion(row+1,col+1,triangle,dp);
        return dp[row][col]=triangle[row][col]+min(left,right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return recursion(0,0,triangle,dp);
    }
};