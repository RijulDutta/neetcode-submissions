class Solution {
public:
    int row, col;
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        row = grid.size();
        col = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    count++;
                    helper(grid, i, j);
                }
            }
        }
        
        return count;
    }

    void helper(vector<vector<char>>&grid, int i, int j){
        if(i<0 || j<0 || i>=row || j>=col) return;
        if(grid[i][j] == '0' || grid[i][j] == '#') return;

        grid[i][j] = '#';

        helper(grid, i+1, j);
        helper(grid, i-1, j);
        helper(grid, i, j+1);
        helper(grid, i, j-1);
    }
};
