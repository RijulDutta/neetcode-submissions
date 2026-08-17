class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;

        unsigned int first = 1;
        unsigned int second = 2;

        for(int i=0; i<n-1; i++){
            unsigned int temp = second;
            second = first + second;
            first = temp;
        }

        return first;
    }
};