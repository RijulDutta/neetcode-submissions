class Solution {
public:
    int maxArea = 0;
    int row;
    int col;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int area = 0;
                if(grid[i][j] == 1){
                    helper(grid, i, j, area);
                }
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }

    void helper(vector<vector<int>>&grid, int i, int j, int&area){
        if(i<0 || j<0 || i>=row || j>=col) return;
        if(grid[i][j] == 0) return;

        area++;
        grid[i][j] = 0;

        helper(grid, i+1, j, area);
        helper(grid, i-1, j, area);
        helper(grid, i, j+1, area);
        helper(grid, i, j-1, area);
    }
};
