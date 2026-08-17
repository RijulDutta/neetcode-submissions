class Solution {
public:
    int row, col;
    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();
        vector<vector<bool>>flag(row, vector<bool>(col, false));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i == 0 || j == 0 || i == row-1 || j == col-1){
                    if(board[i][j] == 'O'){
                        DFS(board, flag, i, j);
                    }
                }
            }
        }
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(flag[i][j] == false){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void DFS(vector<vector<char>>&board, vector<vector<bool>>&flag, int i, int j){
        if(i < 0 || j < 0 || i >= row || j >= col) return;

        if(board[i][j] == 'X') return;

        flag[i][j] = true;

        if(i+1 < row && !flag[i+1][j] && board[i+1][j] == 'O'){DFS(board, flag, i+1, j);}
        if(i-1 >= 0 && !flag[i-1][j] && board[i-1][j] == 'O'){DFS(board, flag, i-1, j);}
        if(j+1 < col && !flag[i][j+1] && board[i][j+1] == 'O'){DFS(board, flag, i, j+1);}
        if(j-1 >= 0 && !flag[i][j-1] && board[i][j-1] == 'O'){DFS(board, flag, i, j-1);}
    }
};
