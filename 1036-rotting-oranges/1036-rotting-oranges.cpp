class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        unordered_map<int,int> fresh;
        unordered_map<int,int> rotten;
        int rows=grid.size();
        int cols=grid[0].size();
        const int sizee=rows*cols;
        vector<vector<int>> adj(sizee);


        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) fresh[i*cols+j]++;
                else if(grid[i][j]==2) rotten[i*cols+j]++;
                if(grid[i][j]!=0){
                    if(i>0 && grid[i-1][j]!=0) adj[i*cols+j].push_back((i-1)*cols+j);
                    if(i<rows-1 && grid[i+1][j]!=0) adj[i*cols+j].push_back((i+1)*cols+j);
                    if(j>0 && grid[i][j-1]!=0) adj[i*cols+j].push_back(i*cols+(j-1));
                    if(j<cols-1 && grid[i][j+1]!=0) adj[i*cols+j].push_back(i*cols+(j+1));
                }
            }
        }

        vector<bool> visited(sizee,false);
        queue<int> q;
        int ans=0;
        int prev_trev=0,total_trev=0;
        for(auto it=rotten.begin();it!=rotten.end();it++) {
            q.push(it->first);total_trev++;visited[it->first]=true;
        }
        if(q.empty() && fresh.size()==0) return 0;
        cout<<total_trev<<endl;
        while(!q.empty()){
            int q_size=q.size();
            if(total_trev==rotten.size()+fresh.size()) return ans;
            while(q_size--){
                int temp=q.front();
                q.pop();
                for(auto it:adj[temp]){
                    if(visited[it]==false){
                        visited[it]=true;q.push(it);total_trev++;
                    }
                }
            }
            cout<<total_trev<<" "<<ans<<endl;
            ans++;
        }
        return -1;
    }
};