class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return (n<0)? helper(1/x, -N): helper(x, N); 
    }

    double helper(double x, long long n){
        if(n == 0) return 1;

        if(n%2 == 0){
            double half = helper(x, n/2);
            return half*half;
        }

        return x*helper(x, n-1);
    }
};
