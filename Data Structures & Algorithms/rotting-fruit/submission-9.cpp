class Solution {
public:
    int row, col;
    int orangesRotting(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();

        queue<pair<int, int>>q;
        int fresh = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh + q.size() == 0) return 0;

        // if(q.empty()) return -1;
        int count = 0;
        int time = 0;
        while(!q.empty()){
            int levelSize = q.size();
            time++;
            for(int k=0; k<levelSize; k++){
                auto [i, j] = q.front();
                cout<<i<<", "<<j<<endl;
                q.pop();
                

                if(i+1<row && grid[i+1][j] == 1){grid[i+1][j] = 2; count++; q.push({i+1, j});}
                if(i-1>=0 && grid[i-1][j] == 1){grid[i-1][j] = 2; count++; q.push({i-1, j});}
                if(j+1<col && grid[i][j+1] == 1){grid[i][j+1] = 2; count++; q.push({i, j+1});}
                if(j-1>=0 && grid[i][j-1] == 1){grid[i][j-1] = 2; count++; q.push({i, j-1});}
            }
        }
        if(count == fresh) return time-1;
        return -1;
    }
};
