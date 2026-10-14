class Solution {
    void Solve(vector<int>& candidates,vector<int>v,vector<vector<int> >& ans,int target,int index)
    {
        if(target==0)
        {
            ans.push_back(v);
            return ;
        }
        if(index>=candidates.size()) return ;

        int n=candidates.size();
        for(int i=index;i<n;i++)
        {
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]<=target)
            {
                v.push_back(candidates[i]);
                Solve(candidates,v,ans,target-candidates[i],i+1);
                v.pop_back();
            }
        }
        return ;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int> >ans;
        sort(candidates.begin(),candidates.end());
        Solve(candidates,v,ans,target,0);
        return ans;
    }
};
