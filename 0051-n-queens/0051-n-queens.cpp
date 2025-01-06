class Solution {
    void put_in_sol(vector<vector<int>> arr,vector<vector<string>> &sol,int n){
        vector<string> temp;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) s=s+'Q';
                else s=s+'.';
            }
            temp.push_back(s);
        }
        sol.push_back(temp);
    }

    bool place_queen(int rows,int cols,vector<vector<int>> arr,int n){
        for(int i=0;i<cols;i++){
            if(arr[rows][i]==1) return false;
        }
        for(int i=0;i<rows;i++){
            if(arr[i][cols]==1) return false;
        }
        for(int i=rows-1,j=cols-1;i>=0 && j>=0;i--,j--){
            if(arr[i][j]==1) return false;
        }
        for(int i=rows-1,j=cols+1;i>=0 && j<n;i--,j++){
            if(arr[i][j]==1) return false;
        }
        return true;
    }

    bool solve(int i,vector<vector<int>> arr,vector<vector<string>> &sol,int n){
        if(i==n){
            put_in_sol(arr,sol,n);
            return true;
            }
        for(int j=0;j<n;j++){
            if(place_queen(i,j,arr,n)==true){
                arr[i][j]=1;
                (solve(i+1,arr,sol,n));
                arr[i][j]=0;
            }
        }
        return false;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<vector<int>> arr(n, vector<int>(n, 0));
        solve(0,arr,sol,n);
        return sol;
    }
};