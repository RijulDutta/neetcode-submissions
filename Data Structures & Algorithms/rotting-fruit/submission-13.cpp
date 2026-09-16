class Solution {
public:
    int row;
    int col;
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        queue<pair<int, int>>q;
        bool has_rotten_flag = false;
        bool has_fresh_flag = false;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2){
                    if(!has_rotten_flag) has_rotten_flag = true;

                    q.push({i, j}); 
                }
                if(!has_fresh_flag && grid[i][j] == 1) has_fresh_flag = true;
            }
        }
        if(!has_fresh_flag) return 0;
        if(!has_rotten_flag) return -1;

        int time = 0;
        while(!q.empty()){
            int levelSize = q.size();
            for(int i=0; i<levelSize; i++){
                    auto curr = q.front();
                q.pop();
                int curr_i = curr.first;
                int curr_j = curr.second;

                if(curr_i+1 < row && grid[curr_i+1][curr_j] == 1){
                    grid[curr_i+1][curr_j] = 2;
                    q.push({curr_i+1, curr_j});
                }
                if(curr_i-1 >= 0 && grid[curr_i-1][curr_j] == 1){
                    grid[curr_i-1][curr_j] = 2;
                    q.push({curr_i-1, curr_j});
                }
                if(curr_j+1 < col && grid[curr_i][curr_j+1] == 1){
                    grid[curr_i][curr_j+1] = 2;
                    q.push({curr_i, curr_j+1});
                }
                if(curr_j-1 >= 0 && grid[curr_i][curr_j-1] == 1){
                    grid[curr_i][curr_j-1] = 2;
                    q.push({curr_i, curr_j-1});
                }
            }
            time++;
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time-1;
    }
};
