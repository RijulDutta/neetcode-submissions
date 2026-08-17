class Solution {
public:
    int row, col;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();

        vector<vector<bool>>isPacific(row, vector<bool>(col, false));
        vector<vector<bool>>isAtlantic(row, vector<bool>(col, false));

        for(int i=0; i<row; i++){
            isPacific[i][0] = true;
            isAtlantic[i][col-1] = true;
        }

        for(int i=0; i<col; i++){
            isPacific[0][i] = true;
            isAtlantic[row-1][i] = true;
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(isPacific[i][j] == true){
                    helper(heights, isPacific, i, j);
                }
                if(isAtlantic[i][j] == true){
                    helper(heights, isAtlantic, i, j);
                }
            }
        }
 

        vector<vector<int>>ans;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(isPacific[i][j] == true && isAtlantic[i][j] == true){
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }

    void helper(vector<vector<int>>&heights, vector<vector<bool>>&vec, int i, int j){
        if(i < 0 || j < 0 || i>=row || j>=col) return;
        
        if(i+1 < row && !vec[i+1][j] && heights[i+1][j] >= heights[i][j]){vec[i+1][j] = true; helper(heights, vec, i+1, j);}
        if(i-1 >= 0 && !vec[i-1][j] && heights[i-1][j] >= heights[i][j]){vec[i-1][j] = true; helper(heights, vec, i-1, j);}
        if(j+1 < col && !vec[i][j+1] && heights[i][j+1] >= heights[i][j]){vec[i][j+1] = true; helper(heights, vec, i, j+1);} 
        if(j-1 >= 0 && !vec[i][j-1] && heights[i][j-1] >= heights[i][j]){vec[i][j-1] = true; helper(heights, vec, i, j-1);}
    }
};
