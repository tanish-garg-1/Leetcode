class Solution {
    int find(int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        else return dp[i][j];
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(str1[i] == str2[j]) dp[i][j]=1+find(i-1,j-1,dp);
                else dp[i][j]=max(find(i-1,j,dp),find(i,j-1,dp));
            }
        }

        int i=m-1,j=n-1;
        string s;
        while(i>=0 && j>=0){
            if(dp[i][j]==find(i-1,j,dp)){
                s=s+str1[i];
                i--;
            }
            else if(dp[i][j]==find(i,j-1,dp)){
                s=s+str2[j];
                j--;
            } 
            else {
                s=s+str2[j];
                i--,j--;}
            }
        if(i>=0) while(i>=0) {s=s+str1[i];i--;}
        else if(j>=0) while(j>=0) {s=s+str2[j];j--;}

        reverse(s.begin(), s.end());
        return s;
    }
};