class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int> >adj;
        for(auto it: prerequisites)
        {
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<int>indegree(numCourses,0);
        for(auto it: adj)
        {
            for(auto v: it.second)
            indegree[v]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans.size()==numCourses?1:0;
    }
};
