class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int count = 0;
        vector<bool>isVisited(n ,false);
        vector<vector<int>>adj(n);

        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0; i<n; i++){
            if(!isVisited[i]){
                count++;
                DFS(adj, isVisited, i);
            }
        }

        return count;
    }

    void DFS(vector<vector<int>>&adj, vector<bool>&isVisited, int curr){
        isVisited[curr] = true;

        for(auto it: adj[curr]){
            if(!isVisited[it]){
                DFS(adj, isVisited, it);
            }
        }
    }
};
