class Solution {
public:
    int maxArea = 0;
    int row, col;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    queue<pair<int, int>>q;
                    helper(grid, area, q,  i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    void helper(vector<vector<int>>&grid, int&area, queue<pair<int, int>>&q, int i, int j){
        q.push({i, j});
        grid[i][j] = 0;
        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();
            area++;

            if(i+1 < row && grid[i+1][j] == 1){grid[i+1][j] = 0; q.push({i+1, j});}
            if(i-1 >= 0 && grid[i-1][j] == 1){grid[i-1][j] = 0; q.push({i-1, j});}
            if(j+1 < col && grid[i][j+1] == 1){grid[i][j+1] = 0; q.push({i, j+1});}
            if(j-1 >= 0 && grid[i][j-1] == 1){grid[i][j-1] = 0; q.push({i, j-1});}
        }
    }
};
