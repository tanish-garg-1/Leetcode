class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows=image.size();
        int cols=image[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int start_color=image[sr][sc];

        while(!q.empty()){
            int q_size=q.size();
            while(q_size--){
                int x=(q.front()).first;
                int y=(q.front()).second;
                image[x][y]=color;
                visited[x][y]=true;
                q.pop();

                if(x>0 && visited[x-1][y]==false && image[x-1][y]==start_color){
                    q.push({x-1,y});
                }
                if(x<rows-1 && visited[x+1][y]==false && image[x+1][y]==start_color){
                    visited[x+1][y]=true;q.push({x+1,y});
                }
                if(y>0 && visited[x][y-1]==false && image[x][y-1]==start_color){
                    visited[x][y-1]=true;q.push({x,y-1});
                }
                if(y<cols-1 && visited[x][y+1]==false && image[x][y+1]==start_color){
                    visited[x][y+1]=true;q.push({x,y+1});
                }
            }
        }
        return image;
    }
};