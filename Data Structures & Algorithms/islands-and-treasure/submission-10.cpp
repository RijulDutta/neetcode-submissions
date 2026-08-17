class Solution {
public:
    int row, col;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        queue<pair<int, int>>q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        int index = 0;
        while(!q.empty()){
            int levelSize = q.size();
        
            for(int k=0; k<levelSize; k++){
                auto [i, j] = q.front();
                q.pop();
                grid[i][j] = index;

                if(i+1 < row && grid[i+1][j] == INT_MAX){grid[i+1][j] = -1; q.push({i+1, j});}
                if(i-1 >= 0 && grid[i-1][j] == INT_MAX){grid[i-1][j] = -1; q.push({i-1, j});}
                if(j+1 < col && grid[i][j+1] == INT_MAX){grid[i][j+1] = -1; q.push({i, j+1});}
                if(j-1 >= 0 && grid[i][j-1] == INT_MAX){grid[i][j-1] = -1; q.push({i, j-1});}
            }
            index++;
        }
    }
};
