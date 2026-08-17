class Solution {
public:
    bool isSafe(int row, int col, vector<string>&board, int n){
        int row_c = row-1;
        int col_c = col-1;

        //Left Diagonal
        while(row_c >= 0 && col_c >= 0){
            if(board[row_c][col_c] == 'Q') return false; 
            row_c--;
            col_c--;
        }

        row_c = row-1;
        col_c = col+1;
        while(row_c >= 0 && col_c <n){
            if(board[row_c][col_c] == 'Q') return false;
            row_c--;
            col_c++;
        }

        row_c = row-1;
        while(row_c >= 0){
            if(board[row_c][col] == 'Q') return false;
            row_c--;
        }
        return true;
    }

    vector<vector<string>>ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        helper(board, n, 0);
        return ans;
    }

    void helper(vector<string>&board, int n, int row){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int i=0; i<n; i++){
            if(!isSafe(row, i, board, n)) continue;

            board[row][i] = 'Q';
            helper(board, n, row+1);
            board[row][i] = '.';
        }
    }
};
