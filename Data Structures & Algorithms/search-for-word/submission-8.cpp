class Solution {
public:
    int row, col;
    bool result = false;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == word[0]){
                    helper(board, word, i, j, 0);
                }
            }
        }

        return result;
    }

    void helper(vector<vector<char>>& board, string& word, int i, int j, int index){
        if(result) return;

        if(index == word.size()){
            result = true;
            return;
        }

        if(i < 0 || i >= row || j < 0 || j >= col) return;
        if(board[i][j] == '.') return;
        if(word[index] != board[i][j]) return;

        char org = board[i][j];
        board[i][j] = '.';
        helper(board, word, i+1, j, index+1);
        helper(board, word, i-1, j, index+1);
        helper(board, word, i, j+1, index+1);
        helper(board, word, i, j-1, index+1);
        board[i][j] = org;
    }
};
