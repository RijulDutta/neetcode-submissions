class Solution {
public: 
    vector<int> topoSort;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inDegree(numCourses, 0);

        for(int i=0; i<prerequisites.size(); i++){
            inDegree[prerequisites[i][1]]++;
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
            topoSort.push_back(course);

            for(int i=0; i<prerequisites.size(); i++){
                if(prerequisites[i][0] == course){
                    inDegree[prerequisites[i][1]]--;

                    if(inDegree[prerequisites[i][1]] == 0) q.push(prerequisites[i][1]);
                }
            }
        }

        if(topoSort.size() != numCourses) return false;
        return true;
    }
};
