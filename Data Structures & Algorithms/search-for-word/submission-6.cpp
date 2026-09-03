class Solution {
public:
    int row;
    int col;
    bool res = false;

    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                helper(board, word, 0, i, j);
            }
        }
        return res;
    }

    void helper(vector<vector<char>>& board, string& word, int idx, int i, int j){
        if(idx == word.size()){
            res = true;
            return;
        }
        if(i < 0 || j < 0 || i>=row || j>=col) return;

        if(word[idx] != board[i][j]) return;

        board[i][j] = '.';
        helper(board, word, idx+1, i+1, j);
        helper(board, word, idx+1, i-1, j);
        helper(board, word, idx+1, i, j+1);
        helper(board, word, idx+1, i, j-1);
        board[i][j] = word[idx];
    }
};