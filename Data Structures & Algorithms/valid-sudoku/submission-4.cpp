class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string>s;
        int row = board.size();
        int col = board[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int ele = board[i][j];
                if(ele == '.') continue; 
                string r = to_string(ele) + " Row : " + to_string(i);
                string c = to_string(ele) + " Col : " + to_string(j);
                string b = to_string(ele) + " Box : " + to_string(i/3) + " AND " + to_string(j/3);

                if(s.find(r) != s.end()) return false;
                if(s.find(c) != s.end()) return false;
                if(s.find(b) != s.end()) return false;

                s.insert(r);
                s.insert(c);
                s.insert(b);
            }
        }
        return true;
    }
};
