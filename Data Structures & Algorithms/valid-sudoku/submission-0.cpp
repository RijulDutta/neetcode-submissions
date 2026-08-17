class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_set<string>s;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                char ele = board[i][j];
                if(ele == '.') continue;
                string row = "Element : "+to_string(ele)+" is in Row : "+ to_string(i);
                string col = "Element : "+to_string(ele)+" is in Col : "+ to_string(j);
                string box = "Element : "+to_string(ele)+" is in Box : "+to_string(i/3)+", "+to_string(j/3);

                if(s.find(row) != s.end() || s.find(col) != s.end() || s.find(box) != s.end()){ 
                    return false;
                }
                s.insert(row);
                s.insert(col);
                s.insert(box);
            }
        }
        return true;
    }
};
