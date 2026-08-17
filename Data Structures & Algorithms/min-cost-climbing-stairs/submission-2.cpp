class Solution {
public:
    int size;
    int minCostClimbingStairs(vector<int>& cost) {
        size = cost.size();
        vector<int>vec(size+1, -1);

        int c1 = f(cost, 0, vec);
        int c2 = f(cost, 1, vec);

        return min(c1, c2);
    }

    int f(vector<int>&cost, int start, vector<int>&vec){
        if(start >= size) return 0;
        if(vec[start] != -1) return vec[start];

        int jump1 = cost[start] + f(cost, start+1, vec);
        int jump2 = cost[start] + f(cost, start+2, vec);

        return vec[start] = min(jump1, jump2);
    }
};
