class Solution {
public:
    int row, col;
    set<pair<int, int>>s;
    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i==0 || i==row-1 || j==0 || j==col-1){
                    if(board[i][j] == 'O'){
                        helper(board, s, i, j);
                    }
                }
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == 'O' && s.find({i, j}) == s.end()){
                    board[i][j] = 'X';
                }
            }
        }
    }

    void helper(vector<vector<char>>& board, set<pair<int, int>>&s, int i, int j){
        if(i < 0 || j < 0 || i >= row || j >= col || board[i][j] == 'X') return;
        if(s.find({i, j}) != s.end()) return;

        s.insert({i, j});
        if(i+1 < row) helper(board, s, i+1, j);
        if(i-1 >= 0) helper(board, s, i-1, j);
        if(j+1 < col) helper(board, s, i, j+1);
        if(j-1 >= 0) helper(board, s, i, j-1);
    }
};
