class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>vec(26, 0);
        priority_queue<int>pq;

        for(char c: tasks){
            vec[c - 'A']++;
        }

        for(int i=0; i<26; i++){
            if(vec[i] > 0){
                pq.push(vec[i]);
            }
        }

        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=0; i<=n; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int i: temp){
                if(i > 0){
                    pq.push(i);
                }
            }

            if(pq.empty()){
                time += temp.size();
            }else{
                time += n+1;
            }
        }

        return time;
    }
};
