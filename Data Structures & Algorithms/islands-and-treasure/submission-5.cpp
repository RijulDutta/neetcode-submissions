class Solution {
public:
    int row, col;
    void islandsAndTreasure(vector<vector<int>>& grid) {\
        row = grid.size();
        col = grid[0].size();

        queue<pair<int, int>>q;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        helper(grid, q);
    }

    void helper(vector<vector<int>>&grid, queue<pair<int, int>>&q){
        int val = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto [x, y] = q.front();
                q.pop();

                if(x+1 < row && grid[x+1][y] == INT_MAX){ grid[x+1][y] = val+1; q.push({x+1, y}); }
                if(x-1 >= 0 && grid[x-1][y] == INT_MAX){ grid[x-1][y] = val+1; q.push({x-1, y}); }
                if(y+1 < col && grid[x][y+1] == INT_MAX){ grid[x][y+1] = val+1; q.push({x, y+1}); }
                if(y-1 >= 0 && grid[x][y-1] == INT_MAX){ grid[x][y-1] = val+1; q.push({x, y-1}); }
            }
            val++;
        }
    }
};
