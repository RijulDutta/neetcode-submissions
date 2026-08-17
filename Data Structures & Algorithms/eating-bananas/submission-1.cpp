class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int size = piles.size();
        int left = 1;
        int maxi = 0;
        for(int i=0; i<size; i++){
            maxi = max(maxi, piles[i]);
        }
        int right = maxi;
        int ans = maxi;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            int totalTime = 0;
            for(int i=0; i<size; i++){
                totalTime += piles[i]/mid;
                if(piles[i]%mid != 0){
                    totalTime++;
                }
            }

            if(totalTime <= h){
                right = mid-1;
                ans = min(ans, mid);
            } 
            else left = mid+1;
        }
        return ans;
    }
};
