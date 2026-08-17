class Solution {
public:
    vector<vector<int>> adj;   // adjacency list: adj[node] = list of connected nodes

    // Can we reach 'target' starting from 'node', using visited edges only?
    bool canReach(int node, int target, vector<bool>& visited) {
        if (node == target) return true;

        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (visited[neighbor]) continue;       // skip already-explored nodes
            if (canReach(neighbor, target, visited)) return true;
        }

        return false; // no path found through this node
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n + 1); // +1 because nodes are labeled 1..n, not 0..n-1

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];

            vector<bool> visited(n + 1, false);

            // Before adding this edge, check: is u already connected to v?
            if (canReach(u, v, visited)) {
                return edge; // yes -> this edge is the redundant one
            }

            // no -> this edge is legitimate, add it to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return {}; // shouldn't happen if input guarantees one redundant edge
    }
};