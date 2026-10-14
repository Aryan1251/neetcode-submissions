class Solution {
    bool Solve(string node,unordered_map<string,vector<string> >& adj,vector<string>& ans,int& n)
    {
        if(ans.size()==n+1)
        {
            return true;
        }
        auto &v=adj[node];
        for(int i=0;i<v.size();i++)
        {
            string str=v[i];
            v.erase(v.begin()+i);
            ans.push_back(str);
            if(Solve(str,adj,ans,n)) return true;
            v.insert(v.begin()+i,str);
            ans.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string> >adj;
        int n=tickets.size();
        for(auto it: tickets)
        {
            auto u=it[0];
            auto v=it[1];
            adj[u].push_back(v);
        }
        for(auto& it: adj)
        {
            sort(it.second.begin(),it.second.end());
        }
        vector<string>ans;
        ans.push_back("JFK");
        Solve("JFK",adj,ans,n);
        return ans;
    }
};