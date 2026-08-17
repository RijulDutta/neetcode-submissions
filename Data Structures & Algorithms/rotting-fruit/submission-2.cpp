class Solution {
public: //use queue
    int row;
    int col;
    queue<pair<int, int>>q;
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        bool isFruitPresent = false;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(!isFruitPresent && grid[i][j] != 0){
                    isFruitPresent = true;
                }

                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }
        
        if(!isFruitPresent) return 0;

        int time = 0;
        helper(grid, time);
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return time-1;
    }

    void helper(vector<vector<int>>&grid, int& time){
        while(!q.empty()){
            int size = q.size();

            for(int i=0; i<size; i++){
                auto [x, y] = q.front();
                q.pop();

                if(x+1 < row && grid[x+1][y] == 1){ grid[x+1][y] = 2; q.push({x+1, y});};
                if(x-1 >= 0 && grid[x-1][y] == 1){ grid[x-1][y] = 2; q.push({x-1, y});};
                if(y+1 < col && grid[x][y+1] == 1){ grid[x][y+1] = 2; q.push({x, y+1});};
                if(y-1 >= 0 && grid[x][y-1] == 1){ grid[x][y-1] = 2; q.push({x, y-1});};
            }
            time++;
        }
    }
};
