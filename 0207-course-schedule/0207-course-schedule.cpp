class Solution {
     bool dfs(int i,vector<vector<int>>& adj,vector<bool>& visited,vector<bool>& path_visited,vector<int>& sol){
        if(visited[i]==false) sol.push_back(i);
        visited[i]=true;
        path_visited[i]=true;
        for(auto it:adj[i]){
            if(path_visited[it]==true) return true;
            if(visited[it]==false){
                if(dfs(it,adj,visited,path_visited,sol)) return true;
            }
        }
        path_visited[i]=false;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses,false);
        vector<bool> path_visited(numCourses,false);
        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> sol;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]) if(dfs(i,adj,visited,path_visited,sol)) return false;
        }
        return true;
    }
};