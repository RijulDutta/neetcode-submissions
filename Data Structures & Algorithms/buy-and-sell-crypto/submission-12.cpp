class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int ans = 0;

        int left = 0;
        
        for(int right = 1; right < size; right++){
            int profit = prices[right] - prices[left];

            if(profit >= 0) ans = max(ans, profit);
            else left = right;
        }

        return ans;
    }
};
