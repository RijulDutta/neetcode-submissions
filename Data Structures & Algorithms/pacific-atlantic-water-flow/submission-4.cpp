class Solution {
public:
    int row;
    int col;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>ans;
        row = heights.size();
        col = heights[0].size();

        vector<vector<bool>>pacific(row, vector<bool>(col, false));
        vector<vector<bool>>atlantic(row, vector<bool>(col, false));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i==0 || j==0) pacific[i][j] = true;
                if(i == row-1 || j == col-1) atlantic[i][j] = true;
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(pacific[i][j] == true){
                    helper(heights, i, j, pacific);
                }
                if(atlantic[i][j] == true){
                    helper(heights, i, j, atlantic);
                }
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(pacific[i][j] == true && atlantic[i][j] == true){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void helper(vector<vector<int>>&heights, int i, int j, vector<vector<bool>>&matrix){
        if(i+1 < row && heights[i+1][j] >= heights[i][j] && !matrix[i+1][j]) {
            matrix[i+1][j] = true;
            helper(heights, i+1, j, matrix);
        }
        if(i-1 >= 0 && heights[i-1][j] >= heights[i][j] && !matrix[i-1][j]) {
            matrix[i-1][j] = true;
            helper(heights, i-1, j, matrix);
        }
        if(j+1 < col && heights[i][j+1] >= heights[i][j] && !matrix[i][j+1]){
            matrix[i][j+1] = true;
            helper(heights, i, j+1, matrix);
        }
        if(j-1 >= 0 && heights[i][j-1] >= heights[i][j] && !matrix[i][j-1]){
            matrix[i][j-1] = true;
            helper(heights, i, j-1, matrix);
        }
    }
};
