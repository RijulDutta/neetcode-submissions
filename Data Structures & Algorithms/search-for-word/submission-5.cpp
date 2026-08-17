class Solution {
public:
    bool res = false;
    int row;
    int col;
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        string inter;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                //if(board[i][j] != word[0]) continue;

                //inter.push_back(board[i][j]);
                helper(board, word, inter, 0, i, j);
                //inter.pop_back();
            }
        }
        return res;
    }

    void helper(vector<vector<char>>&board, string word, string inter, int index, int i, int j){
        if(board[i][j] != word[index]) return;

        inter.push_back(board[i][j]);
        if(inter == word){
            res = true;
            return;
        }
        
        int original = board[i][j];
        board[i][j] = '#';

        if(i+1 < row) helper(board, word, inter, index+1, i+1, j);
        if(i-1 >= 0) helper(board, word, inter, index+1, i-1, j);
        if(j+1 < col) helper(board, word, inter, index+1, i, j+1);
        if(j-1 >= 0) helper(board, word, inter, index+1, i, j-1);

        inter.pop_back();
        board[i][j] = original;
    }
};
