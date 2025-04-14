class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        int rows=mat.size();
        int cols=mat[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        int dis=1;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0) {q.push({i,j});
                visited[i][j]=true;
                }
            }
        }
        while(!q.empty()){
            int q_size=q.size();
            while(q_size--){
                int x=(q.front()).first;
                int y=(q.front()).second;
                q.pop();
                
                if(x>0 && visited[x-1][y]==false) {mat[x-1][y]=dis;visited[x-1][y]=true;q.push({x-1,y});}
                if(x<rows-1 && visited[x+1][y]==false) {mat[x+1][y]=dis;visited[x+1][y]=true;q.push({x+1,y});}
                if(y>0 && visited[x][y-1]==false) {mat[x][y-1]=dis; visited[x][y-1]=true;q.push({x,y-1});}
                if(y<cols-1 && visited[x][y+1]==false) {mat[x][y+1]=dis;visited[x][y+1]=true;q.push({x,y+1});}
            }
            dis++;
        }
        return mat;
    }
};