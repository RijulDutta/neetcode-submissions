class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;

        for(int stone: stones){
            pq.push(stone);
        }

        while(!pq.empty()){
            if(pq.size() == 1) return pq.top();

            int s1 = pq.top();
            pq.pop();
            int s2 = pq.top();
            pq.pop();

            if(s1 != s2) pq.push(abs(s1-s2)); 
        }

        return 0;
    }
};
