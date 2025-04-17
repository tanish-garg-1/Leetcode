class Solution {
    bool dfs_trav(vector<vector<int>>& graph,vector<int>& visited,int x,int color){
        visited[x]=color;
        for(auto it:graph[x]){
            if(visited[it]==visited[x]) return false;
            if(visited[it]==0) if(!dfs_trav(graph,visited,it,-color)) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int sizee=graph.size();
        vector<int> visited(graph.size(),0);
        for (int i = 0; i < graph.size(); ++i) {
            if (visited[i] == 0) {
                if (dfs_trav(graph, visited, i, 1)==false)
                return false;
            }   
        }
        return true;
    }
};