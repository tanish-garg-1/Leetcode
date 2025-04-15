#include <unordered_map>
#include <utility>
#include <functional>

// Define a custom hash function for std::pair<int, int>
struct PairHash {
    std::size_t operator()(const std::pair<int, int>& p) const noexcept {
        // Combine the hash of the two elements (this is one common approach)
        std::size_t h1 = std::hash<int>{}(p.first);
        std::size_t h2 = std::hash<int>{}(p.second);
        return h1 ^ (h2 << 1);  // or use another combination method
    }
};


class Solution {
    bool all_sorrounded(int x,int y,vector<vector<char>>& board,vector<vector<bool>>& visited,std::unordered_map<std::pair<int, int>, int, PairHash>& mymap){
        bool ans=true;
        stack<pair<int,int>> s;
        s.push({x,y});
        visited[x][y]=true;
        mymap[{x,y}]++;
        
        while(!s.empty()){
            int i=(s.top()).first;
            int j=(s.top()).second;
            if(i==0 || j==0 || i==board.size()-1 || j==board[0].size()-1){
            ans=false;
            }
            s.pop();
            
            if(i>0 && board[i-1][j]=='O' && visited[i-1][j]==false){
                visited[i-1][j]=true;mymap[{i-1,j}]++;s.push({i-1,j});
            }
            if(i<board.size()-1 && board[i+1][j]=='O' && visited[i+1][j]==false){
                visited[i+1][j]=true;mymap[{i+1,j}]++;s.push({i+1,j});
            }
            if(j>0 && board[i][j-1]=='O' && visited[i][j-1]==false){
                visited[i][j-1]=true;mymap[{i,j-1}]++;s.push({i,j-1});
            }
            if(j<board[0].size()-1 && board[i][j+1]=='O' && visited[i][j+1]==false){
                visited[i][j+1]=true;mymap[{i,j+1}]++;s.push({i,j+1});
            }
        }
        return ans;
    }
public:
    void solve(vector<vector<char>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='X') visited[i][j]=true;
                if(board[i][j]=='O' && visited[i][j]==false){
                    std::unordered_map<std::pair<int, int>, int, PairHash> mymap;
                    bool mark_all_x=all_sorrounded(i,j,board,visited,mymap);
                    if(mark_all_x==true){
                        for(auto it:mymap){
                            board[it.first.first][it.first.second]='X';
                        }
                    }
                }
            }
        }
        return;
    }
};