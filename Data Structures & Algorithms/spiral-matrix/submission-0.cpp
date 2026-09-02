class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int srow = 0;
        int erow = m-1;
        int scol = 0;
        int ecol = n-1;

        while(srow<=erow && scol<=ecol){
            //Top Horiontal
            for(int j = scol; j <= ecol; j++){
                ans.push_back(matrix[srow][j]);
            }
            //Right Vertical
            for(int i = srow+1; i<= erow; i++){
                ans.push_back(matrix[i][ecol]);
            }
            //Bottom Horizontal
            for(int j=ecol-1; j>=scol; j--){
                if(srow == erow) break;
                ans.push_back(matrix[erow][j]);
            }
            //Left Vertical;
            for(int i=erow-1; i>=srow+1; i--){
                if(scol == ecol) break;
                ans.push_back(matrix[i][scol]);
            }

            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};
