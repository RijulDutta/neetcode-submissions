class Solution {
public:
    int row;
    int col;
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int count = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                    helper(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void helper(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j] == '0') return;

        grid[i][j] = '0';

        helper(grid, i+1, j);
        helper(grid, i-1, j);
        helper(grid, i, j+1);
        helper(grid, i, j-1);
    }
};
