class Solution {
public:
    int row;
    int col;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        queue<pair<int, int>>q;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        int dist = 1;
        while(!q.empty()){
            int levelSize = q.size();
            
            for(int i=0; i<levelSize; i++){
                auto curr = q.front();
                q.pop();

                int curr_i = curr.first;
                int curr_j = curr.second;

                if(curr_i+1 < row && grid[curr_i+1][curr_j] == INT_MAX){
                    grid[curr_i+1][curr_j] = dist;
                    q.push({curr_i+1, curr_j});
                } 

                if(curr_i-1 >= 0 && grid[curr_i-1][curr_j] == INT_MAX){
                    grid[curr_i-1][curr_j] = dist;
                    q.push({curr_i-1, curr_j});
                }

                if(curr_j+1 < col && grid[curr_i][curr_j+1] == INT_MAX){
                    grid[curr_i][curr_j+1] = dist;
                    q.push({curr_i, curr_j+1});
                } 
                if(curr_j-1 >= 0 && grid[curr_i][curr_j-1] == INT_MAX){
                    grid[curr_i][curr_j-1] = dist;     
                    q.push({curr_i, curr_j-1});
                } 
            }
            dist++;
        }
    }
};
