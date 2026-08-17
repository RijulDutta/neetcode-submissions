class Solution {
public:
    int row, col;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        vector<vector<bool>>isPacific(row, vector<bool>(col, false));
        vector<vector<bool>>isAtlantic(row, vector<bool>(col, false));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(i == 0 || j == 0){
                    isPacific[i][j] = true;
                }
                if(i == row-1 || j == col-1){
                    isAtlantic[i][j] = true;
                }
            }
        }
        helper(heights, isPacific);
        helper(heights, isAtlantic);

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

    void helper(vector<vector<int>>&heights, vector<vector<bool>>&arr){//here arr is only acting as the flag to further continue or not
        queue<pair<int, int>>q;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(arr[i][j] == true){
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            if(i+1 < row && !arr[i+1][j] && heights[i+1][j] >= heights[i][j]){arr[i+1][j] = true; q.push({i+1, j});}
            if(i-1 >=0 && !arr[i-1][j] && heights[i-1][j] >= heights[i][j]){arr[i-1][j] = true; q.push({i-1, j});}
            if(j+1 < col && !arr[i][j+1] && heights[i][j+1] >= heights[i][j]){arr[i][j+1] = true; q.push({i, j+1});}
            if(j-1 >= 0 && !arr[i][j-1] && heights[i][j-1] >= heights[i][j]){arr[i][j-1] = true; q.push({i, j-1});}
        }
    }
};
