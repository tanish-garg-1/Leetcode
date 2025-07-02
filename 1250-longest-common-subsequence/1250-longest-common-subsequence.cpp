class Solution {
    int recursion(int i,int j,string& text1,string& text2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i]==text2[j]) return 1+ recursion(i-1,j-1,text1,text2,dp);
        else return dp[i][j]=max(recursion(i-1,j,text1,text2,dp),recursion(i,j-1,text1,text2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i=text1.size(),j=text2.size();
        vector<vector<int>> dp(i+1,vector<int>(j+1,-1));
        return recursion(i-1,j-1,text1,text2,dp);
    }
};