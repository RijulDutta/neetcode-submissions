class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>s; 

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;
                string row = "Element : "+ to_string(board[i][j])+" Row : "+to_string(i);
                string col = "Element : "+ to_string(board[i][j])+" Column : "+to_string(j);
                string box = "Element : "+ to_string(board[i][j])+" X : "+to_string(i/3)+" Y : "+to_string(j/3);

                if(s.find(row) != s.end() || s.find(col) != s.end() || s.find(box) != s.end()) return false;

                s.insert(row);
                s.insert(col);
                s.insert(box);
            }
        }
        return true;
    }
};
