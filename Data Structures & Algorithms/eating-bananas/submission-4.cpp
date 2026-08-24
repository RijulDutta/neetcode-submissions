class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = INT_MIN;
        for(int it: piles){
            right = max(right, it);
        }

        while(left < right){
            int mid = left + (right-left)/2;
            int timeTaken = getHours(piles, mid);

            if(timeTaken <= h){
                right = mid;
            }else{
                left = mid+1;
            }
        }

        return left;
    }

    int getHours(vector<int>&piles, int x){
        int hours = 0;

        for(int it: piles){
            if(it%x == 0) hours += it/x;
            else hours += it/x+1;
        }
        return hours;
    }
};
