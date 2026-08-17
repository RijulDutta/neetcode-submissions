class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<vector<int>>adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool>isVisited(n, false);

        for(int i=0; i<n; i++){
            if(!isVisited[i]){
                DFS(adj, i, isVisited);
                count++;
            }
        }

        return count;
    }

    void DFS(vector<vector<int>>&adj, int i, vector<bool>&isVisited){
        isVisited[i] = true;

        for(auto it: adj[i]){
            if(!isVisited[it]){
                DFS(adj, it, isVisited);
            }
        }
    }
};
