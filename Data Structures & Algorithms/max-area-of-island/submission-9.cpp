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
                    helper(grid, area, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }

    void helper(vector<vector<int>>&grid, int&area, int i, int j){
        if(i<0 || j<0 || i>=row || j>=col) return;
        if(grid[i][j] == 0) return;

        grid[i][j] = 0;
        area++;

        helper(grid, area, i+1, j);
        helper(grid, area, i-1, j);
        helper(grid, area, i, j+1);
        helper(grid, area, i, j-1);
    }
};
