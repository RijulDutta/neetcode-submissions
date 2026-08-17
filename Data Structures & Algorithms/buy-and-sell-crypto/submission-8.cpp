class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int size = prices.size();
        int left = 0;
        for(int right = 1; right<size; right++){
            if(prices[right] < prices[left]){
                left = right;
                continue;
            }
            int profit = prices[right] - prices[left];
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
