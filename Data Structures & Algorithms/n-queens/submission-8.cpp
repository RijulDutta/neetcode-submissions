class Solution {
public:
    vector<vector<string>>ans;

    bool isSafe(vector<string>& board, int n, int row, int col){
        //checking the vertical above
        for(int i=0; i<row; i++){
            if(board[i][col] == 'Q') return false;
        }

        int row_c = row;
        int col_c = col;

        while(row_c >= 0 && col_c >= 0){
            if(board[row_c--][col_c--] == 'Q') return false;
        }

        row_c = row;
        col_c = col;

        while(row_c >= 0 && col_c < n){
            if(board[row_c--][col_c++] == 'Q') return false;
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>inter(n, string(n, '.'));
        helper(n, inter, 0);
        return ans;       
    }

    void helper(int n, vector<string>& inter, int r){
        if(r == n){
            ans.push_back(inter);
            return;
        }

        for(int i=0; i<n; i++){
            if(!isSafe(inter, n, r, i)) continue;

            inter[r][i] = 'Q';
            helper(n, inter, r+1);
            inter[r][i] = '.';
        }
    }
};
