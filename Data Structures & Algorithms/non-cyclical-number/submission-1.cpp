class Solution {
public:
    unordered_set<int>s;
    bool isHappy(int n) {
        if(n == 1) return true;
        if(s.find(n) != s.end()) return false;
        s.insert(n);

        int num = n;
        int sum = 0;
        while(num > 0){
            int digit = num%10;
            sum += digit*digit;
            num /= 10;
        }
        return isHappy(sum);
    }
};
