class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int slow = 0;
        int fast = 0;

        while(true){
            slow = arr[slow];
            fast = arr[arr[fast]];

            if(slow == fast) break;
        }

        int x = 0;
        while(x != slow){
            x = arr[x];
            slow = arr[slow];
        }

        return x;
    }
};
