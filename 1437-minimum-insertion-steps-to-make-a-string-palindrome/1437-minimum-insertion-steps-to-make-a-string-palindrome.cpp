class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
        return n-dp[0][n-1];
    }
};

// class Solution {
//     int recursion(int i,int j,string& s,vector<vector<int>>& dp){
//         if(i>j) return 0;
//         if(i==j) return 1;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(s[i]==s[j]) return dp[i][j]=2+recursion(i+1,j-1,s,dp);
//         else return max(recursion(i+1,j,s,dp),recursion(i,j-1,s,dp));
//     }
// public:
//     int minInsertions(string s) {
//         int n=s.size();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         return n-recursion(0,n-1,s,dp);
//     }
// };