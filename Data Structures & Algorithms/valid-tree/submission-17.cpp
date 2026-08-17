class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        
        vector<vector<int>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool>isVisited(n, false);
        queue<int>q;
        q.push(0);
        isVisited[0] = true;
        int count = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto it: adj[curr]){
                if(!isVisited[it]) {
                    isVisited[it] = true;
                    count++;
                    q.push(it);
                }
            }
        }
        if(count == n) return true;
        return false;
    }
};
