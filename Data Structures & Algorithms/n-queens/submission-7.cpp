class Solution {
public:
    int n;
    vector<vector<string>>ans;

    bool isSafe(vector<string>&board, int i, int j){
        int i_c = i;
        int j_c = j;

        //checking col
        while(j_c >= 0){
            if(board[i][j_c--] == 'Q') return false;
        }

        //checking row
        while(i_c >= 0){
            if(board[i_c--][j] == 'Q') return false;
        }
        
        //checking upper left diagonal
        i_c = i;
        j_c = j;
        while(i_c >= 0 && j_c >= 0){
            if(board[i_c--][j_c--] == 'Q') return false;
        }

        //checking upper right diagonal
        i_c = i;
        j_c = j;
        while(i_c >= 0 && j_c < n){
            if(board[i_c--][j_c++] == 'Q') return false;
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        this->n = n;
        vector<string> board(n, string(n, '.'));
        helper(board, 0);
        return ans;
    }

    void helper(vector<string>&board, int rowNo){
        if(rowNo == n){
            ans.push_back(board);
            return;
        }

        for(int i=0; i<n; i++){
            if(isSafe(board, rowNo, i)){
                board[rowNo][i] = 'Q';
                helper(board, rowNo+1);
                board[rowNo][i] = '.';
            }
        }
    }
};
