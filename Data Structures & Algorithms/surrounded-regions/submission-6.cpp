class Solution {
public:
    int row;
    int col;
    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();

        vector<vector<bool>>flag(row, vector<bool>(col, false));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i == 0 || i == row-1 || j == 0 || j == col-1){
                    if(board[i][j] == 'O'){
                        helper(board, i, j, flag);
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

    void helper(vector<vector<char>>&board, int i, int j, vector<vector<bool>>&flag){
        if(i<0 || j<0 || i>=row || j>=col) return;
        if(board[i][j] == 'X') return;
        if(flag[i][j]) return;

        flag[i][j] = true;
        helper(board, i+1, j, flag);
        helper(board, i-1, j, flag);
        helper(board, i, j+1, flag);
        helper(board, i, j-1, flag);
    }
};
