class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalGas = 0;
        int totalCost = 0;

        int start = 0;
        int currGas = 0;

        for(int i=0; i<n; i++){
            currGas += gas[i];
            if(currGas-cost[i] < 0){
                start = i+1;
                currGas = 0;
            }else{
                currGas -= cost[i]; 
            }
            totalGas += gas[i];
            totalCost += cost[i];
        }

        return (totalGas < totalCost)? -1: start;
    }
};
