class Solution {
    bool dfs(string s,unordered_map<string,vector<string> >& adj,vector<string> ans,vector<string>& res,int n)
    {
        ans.push_back(s);
        if(ans.size()==n+1)
        {
            res=ans;
            return true;
        }
        auto &nbr=adj[s];
        for(int i=0;i<nbr.size();i++)
        {
            auto v=nbr[i];
            nbr.erase(nbr.begin()+i);
            if(dfs(v,adj,ans,res,n)) return true;
            nbr.insert(nbr.begin()+i,v);
        }
        ans.pop_back();
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string> >adj;
        vector<string>ans;
        vector<string>res;
        int n=tickets.size();
        for(auto it: tickets)
        {
            string u=it[0];
            string v=it[1];
            adj[u].push_back(v);
        }
        for(auto& v: adj)
        {
            sort(v.second.begin(),v.second.end());
        }
        dfs("JFK",adj,ans,res,n);
        return res;
    }
};
