class Solution {
    bool is_safe(int x,int row,int col,int n,vector<vector<char>>& board){        int root=sqrt(n);

            for(int i=0;i<n;i++){
                if((board[row][i] != '.' && board[row][i]-'0'==x) || (board[i][col] != '.' && board[i][col]-'0'==x)) return false;
            }


            for(int i=(row/root)*root;i<(row/root)*root+root;i++){
                for(int j=(col/root)*root;j<(col/root)*root+root;j++){
                    if(board[i][j] != '.' && board[i][j]-'0'==x) return false;
                }
            }

            return true;
    }
    bool function(int n,vector<vector<char>>& board){
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]=='.'){
                    for(int x=1;x<=n;x++){
                        if(is_safe(x,row,col,n,board)) {
                            board[row][col]=x+'0';
                            if(function(n,board)) return true; 
                            board[row][col]='.';
                        }
                    }
                    return false;  
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        function(n,board);
        return ;
    }
};