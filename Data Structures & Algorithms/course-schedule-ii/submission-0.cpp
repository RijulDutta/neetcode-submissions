class Solution {
public:
    vector<int> topo;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses, 0);
        vector<vector<int>>adj(numCourses);

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }

        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();

            topo.push_back(course);

            for(auto it: adj[course]){
                inDegree[it]--;

                if(inDegree[it] == 0) q.push(it);
            }
        }

        if(topo.size() == numCourses) return topo;
        return {};
    }
};
