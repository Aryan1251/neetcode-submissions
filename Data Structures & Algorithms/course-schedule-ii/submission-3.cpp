class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int> >adj;
        for(auto it: prerequisites)
        {
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            for(auto it: adj[i])
            indegree[it]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        vector<int>v;
        while(!q.empty())
        {
            auto node=q.front();
            v.push_back(node);
            q.pop();

            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(v.size()==numCourses) return v;
        return {}; 
    }
};
