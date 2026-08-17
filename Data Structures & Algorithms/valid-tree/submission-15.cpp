class Solution {
public:
    bool ans = true;
    int count = 0;
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<int> isVisited(n, false);

        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        DFS(adj, -1, 0, isVisited);

        if(!ans) return ans;

        if(count == n) return true;
        return false;
    }

    void DFS(vector<vector<int>>&adj, int prev, int curr, vector<int>&isVisited){
        isVisited[curr] = true;
        count++;

        for(int it: adj[curr]){
            if(it == prev) continue;

            if(isVisited[it]) ans = false;
            else if(ans){
                 DFS(adj, curr, it, isVisited);
            }
        }
    }
};
