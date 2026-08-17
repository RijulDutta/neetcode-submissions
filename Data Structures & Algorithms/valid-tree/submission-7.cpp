class Solution {
public:
    vector<int> order;
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool> isVisited(n, false);

        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int>q;
        q.push(0);
        //isVisited[0] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            order.push_back(curr);
            isVisited[curr] = true;
            
            for(int it: adj[curr]){
                if(!isVisited[it]){
                    q.push(it);
                    //isVisited[it] = true;
                }    
            }
        }

        if(order.size() == n) return true;
        return false;
    }
};
