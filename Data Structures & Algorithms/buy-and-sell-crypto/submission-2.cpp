class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int maxProf = 0;

        vector<int> rightMax(size, 0);
        int maxi = 0;
        for(int i=size-1; i>=0; i--){
            maxi = max(maxi, prices[i]);
            rightMax[i] = maxi;
        }

        int mini = INT_MAX;
        for(int i=0; i<size; i++){
            mini = min(mini, prices[i]);

            int profit = rightMax[i] - mini;

            maxProf = max(maxProf, profit);
        }

        return maxProf;
    }
};
