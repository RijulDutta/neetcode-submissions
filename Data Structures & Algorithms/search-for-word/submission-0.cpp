class Solution {
public:
    bool ans = false;
    string word;
    int rows, cols;
    bool exist(vector<vector<char>>& board, string word) {
        this->word = word;
        //set<pair<int, int>>isVisited;
        string inter;
        rows = board.size();
        cols = board[0].size();

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                // helper(board, inter, isVisited, 0, i, j);
                helper(board, inter, 0, i, j);
            }
        }
        return ans;
    }

    //void helper(vector<vector<char>>& board, string&inter, set<pair<int, int>>&isVisited, int index, int i, int j){
    void helper(vector<vector<char>>& board, string&inter, int index, int i, int j){
        if(i < 0 || j < 0 || i >= rows || j >= cols) return;
        //if(isVisited.find({i,j}) != isVisited.end()) return;
        
        if(word[index] != board[i][j]) return;
        
        //isVisited.insert({i, j});
        char original = board[i][j];
        inter.push_back(board[i][j]);
        board[i][j] = '#';

        if(inter == word){
            ans = true;
            return;
        }
        
        // helper(board, inter, isVisited, index+1, i+1, j);
        // helper(board, inter, isVisited, index+1, i-1, j);
        // helper(board, inter, isVisited, index+1, i, j+1);
        // helper(board, inter, isVisited, index+1, i, j-1);

        helper(board, inter, index+1, i+1, j);
        helper(board, inter, index+1, i-1, j);
        helper(board, inter, index+1, i, j+1);
        helper(board, inter, index+1, i, j-1);
        
        board[i][j] = original;
        //isVisited.erase({i, j});
        inter.pop_back();
    }
};