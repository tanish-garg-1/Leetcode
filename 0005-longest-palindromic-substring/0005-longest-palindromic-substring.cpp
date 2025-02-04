class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n<=1) return s;
        int ans=1;
        string sol;
        sol=sol+s[0];

        for(double i=1.5;i<n;i+=1.0){
            int x=floor(i-1);int y=floor(i);
            int temp_ans=0;
            if(s[x]==s[y]){
                while(x>=0 && y<=n-1 && s[x]==s[y]) {
                    temp_ans=temp_ans+2;
                    x--;
                    y++;
                }
            }
            if(temp_ans>ans) {
                sol.clear();
                sol=s.substr(x+1,y-x-1);
                ans=temp_ans;
            }
        }

        for(double i=1.5;i<n-1;i+=1.0){
            int x=floor(i-1);int y=ceil(i);
            int temp_ans=1;
            if(s[x]==s[y]){
                while(x>=0 && y<=n-1 && s[x]==s[y]) {
                    temp_ans=temp_ans+2;
                    x--;
                    y++;
                }
            }
            if(temp_ans>ans) {
                sol.clear();
                sol=s.substr(x+1,y-x-1);
                ans=temp_ans;
            }
        }

        return sol;
    }
};