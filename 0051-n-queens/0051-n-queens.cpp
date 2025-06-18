class Solution {
    bool is_safe(int row,int col,int n,vector<string>& temp){
        for(int i=0;i<n;i++){
            if(temp[row][i]=='Q' || temp[i][col]=='Q') return false;
        }

        for (int x = row - 1, y = col - 1; x >= 0 && y >= 0; x--, y--) {
            if (temp[x][y] == 'Q') return false;
        }

        for (int x = row - 1, y = col + 1; x >= 0 && y < n; x--, y++) {
            if (temp[x][y] == 'Q') return false;
        }
        return true;
    }
    void find_sol(int row,int n,vector<string>& temp,vector<vector<string>>& sol){
        if(row==n){
            sol.push_back(temp);
            return;
        }
        for(int col=0;col<n;col++){
            if(is_safe(row,col,n,temp)){
                temp[row][col]='Q';
                find_sol(row+1,n,temp,sol);
                temp[row][col]='.';
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> temp(n, string(n, '.'));
        find_sol(0,n,temp,sol);
        return sol;
    }
};