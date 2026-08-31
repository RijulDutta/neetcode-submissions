class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        vector<int>mp(26, 0);
        priority_queue<int>pq; //pair<freq, char>

        for(char task: tasks){
            mp[task - 'A']++;
        }

        for(int it: mp){
            if(it > 0) pq.push(it);
        }

        while(!pq.empty()){
            vector<int>temp;
            for(int i=0; i<n+1; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int it: temp){
                if(it > 0){
                    pq.push(it);
                }
            }

            if(pq.empty()){ //Last case if evry process finishes
                time += temp.size();
            }else{
                time += n+1;
            }
        }

        return time;
    }
};
