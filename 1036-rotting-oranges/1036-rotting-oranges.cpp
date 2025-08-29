class Solution {
    void rott_oranges(queue<pair<int,int>> &q,int row,int col,vector<vector<int>>& grid,int &fresh){
        if(row>0 && grid[row-1][col]==1) {
            grid[row-1][col]=2;q.push({row-1,col});fresh--;
        }
        if(col>0 && grid[row][col-1]==1) {
            grid[row][col-1]=2;q.push({row,col-1});fresh--;
        }
        if(row<grid.size()-1 && grid[row+1][col]==1) {
            grid[row+1][col]=2;q.push({row+1,col});fresh--;
        }
        if(col<grid[0].size()-1 && grid[row][col+1]==1) {
            grid[row][col+1]=2;q.push({row,col+1});fresh--;
        }
        return;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int rotten=0,fresh=0,empty=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) empty++;
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2){ 
                    q.push({i,j});rotten++;
                }
            }
        }
        int ans=-1;
        if(rotten==0) ans=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                rott_oranges(q,q.front().first,q.front().second,grid,fresh);
                q.pop();
            }
            ans++;
        }
        if(fresh==0) return ans;
        else return -1;
    }
};