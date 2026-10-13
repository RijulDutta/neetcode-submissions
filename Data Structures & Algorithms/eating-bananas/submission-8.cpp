class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;

        for(int i=0; i<piles.size(); i++){
            maxi = max(maxi, piles[i]);
        }

        int left = 1;
        int right = maxi;

        while(left < right){
            int mid = left + (right-left)/2;

            int hours = getHours(piles, mid);
            if(hours <= h) right = mid;
            else left = mid+1;
        }

        return left;
    }

    int getHours(vector<int>& piles, int rate){
        int count = 0;
        for(int i=0; i<piles.size(); i++){
            count += piles[i]/rate;

            if(piles[i]%rate != 0){
                count++;
            }
        }
        return count;
    }
};
