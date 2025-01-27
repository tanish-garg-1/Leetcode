class Solution {
    bool isValid(int row, int col, char num, vector<vector<char>>& board) {
        int subGridSize = sqrt(board.size());
        for (int i = 0; i < board.size(); i++) {

            if (board[row][i] == num || board[i][col] == num) 
                return false;

            int subRow = subGridSize * (row / subGridSize) + i / subGridSize;
            int subCol = subGridSize * (col / subGridSize) + i % subGridSize;
            if (board[subRow][subCol] == num) 
                return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(row, col, num, board)) {
                            board[row][col] = num;
                            if (solve(board)) return true; 
                            board[row][col] = '.'; 
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
        solve(board);
    }
};
