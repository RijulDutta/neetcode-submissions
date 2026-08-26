class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int>diff(n);

        for(int i=0; i<n; i++){
            diff[i] = gas[i] - cost[i];
        }

        int start = 0;
        int sum = 0;

        int totalGas = 0;
        int totalCost = 0;

        for(int i=0; i<n; i++){
            sum += diff[i];
            if(sum < 0){
                start = i+1;
                sum = 0;
            }

            totalGas += gas[i];
            totalCost += cost[i];
        }

        return (totalGas < totalCost)? -1: start;
    }
};
