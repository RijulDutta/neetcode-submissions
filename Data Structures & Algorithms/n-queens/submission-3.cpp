class Solution {
public:
    vector<vector<string>>ans;
    int n;

    bool isSafe(int row, int col, vector<string>board){
        int row_c = row-1; // cause the row is not added till now
        int col_c = col-1; 

        while(row_c >= 0 && col_c >= 0){
            if(board[row_c][col_c] == 'Q') return false;
            row_c--;
            col_c--;
        }
        
        row_c = row-1; // cause the current row is not added till now
        col_c = col+1;

        while(row_c >= 0 && col_c < n){
            if(board[row_c][col_c] == 'Q') return false;
            row_c--;
            col_c++;
        }
        
        row_c = row-1; //cause the current row is not added till now
        while(row_c >= 0){
            if(board[row_c][col] == 'Q') return false;
            row_c--;
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string>board;
        helper(board, 0);
        return ans;
    }

    void helper(vector<string>&board, int row){
        if(row == n){
            ans.push_back(board);
            return;
        }

        
        for(int i=0; i<n; i++){
            if(!isSafe(row, i, board)) continue;

            string single_row(n, '.');
            single_row[i] = 'Q';

            board.push_back(single_row);
            helper(board, row+1);
            board.pop_back();
        }
    }
};
