class Solution {
public:
    int row;
    int col;
    int maxSum = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                int currSum = 0; 
                if(grid[i][j] == 1) helper(grid, currSum, i, j);
                maxSum = max(maxSum, currSum);
            }
        }
        return maxSum;
    }

    void helper(vector<vector<int>>& grid, int& currSum, int i, int j){
        if(i < 0 || j < 0 || i>=row || j>=col || grid[i][j] == 0) return;

        grid[i][j] = 0;
        currSum++;

        helper(grid, currSum, i+1, j);
        helper(grid, currSum, i-1, j);
        helper(grid, currSum, i, j+1);
        helper(grid, currSum, i, j-1);
    }
};
