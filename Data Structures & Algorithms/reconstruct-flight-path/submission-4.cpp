class Solution {
    bool dfs(map<string,vector<string> > &adj,vector<string>& ans,string str,int n)
    {
        if(ans.size()==n+1)
        {
            return true;
        }
        auto &nbr=adj[str];
        for(int i=0;i<nbr.size();i++)
        {
            string s=nbr[i];
            ans.push_back(s);
            nbr.erase(nbr.begin()+i);
            if(dfs(adj,ans,s,n)) return true;
            nbr.insert(nbr.begin()+i,s);
            ans.pop_back();
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string,vector<string> >adj;
        int n=tickets.size();
        for(auto str: tickets)
        {
            string s1=str[0];
            string s2=str[1];
            adj[s1].push_back(s2);
        }
        for(auto &it:adj)
        {
            auto &v=it.second;
            sort(v.begin(),v.end());
        }
        vector<string>ans;
        ans.push_back("JFK");
        dfs(adj,ans,"JFK",n);
        return ans;
    }
};
