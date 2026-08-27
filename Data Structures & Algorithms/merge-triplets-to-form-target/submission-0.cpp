class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        for(int i=0; i<triplets.size(); i++){
            for(int j=0; j<target.size(); j++){
                if(triplets[i][j] > target[j]){
                    triplets.erase(triplets.begin()+i);
                    i--;
                    break;
                }
            }
        }

        if(triplets.empty()) return false;

        for(int i=0; i<target.size(); i++){
            for(int j = 0; j<triplets.size(); j++){
                if(triplets[j][i] == target[i]){
                    break;
                }

                if(j == triplets.size()-1) return false;
            }
        }

        return true;
    }
};
