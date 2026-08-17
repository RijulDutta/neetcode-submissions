class DSU{
public:
    vector<int>parent;
    vector<int>rank;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1);

        for(int i=1; i<n+1; i++){
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int a){
        if(a == parent[a]) return a;

        return parent[a] = find(parent[a]);
    }

    void Union(int a, int b){
        int a_parent = find(a);
        int b_parent = find(b);

        if(a_parent == b_parent) return;

        if(rank[a_parent] > rank[b_parent]){
            parent[b_parent] = a_parent;
        }else if(rank[a_parent] < rank[b_parent]){
            parent[a_parent] = b_parent;
        }else{
            parent[b_parent] = a_parent;
            rank[a_parent]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            if(dsu.find(u) == dsu.find(v)) return edge;

            dsu.Union(u, v);
        }
        return {};
    }
};
