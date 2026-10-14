class Solution {
    void Solve(vector<int>& candidates,int index,int target,vector<vector<int> >& ans,vector<int>v)
    {
        if(target==0)
        {
            ans.push_back(v);
            return ;
        }
        if(index>=candidates.size()) return ;

        for(int i=index;i<candidates.size();i++)
        {
            if(index!=i && candidates[i]==candidates[i-1]) continue;
            if(target>=candidates[i])
            {
                v.push_back(candidates[i]);
                Solve(candidates,i+1,target-candidates[i],ans,v);
                v.pop_back();
            }
        }
        return ;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> >ans;
        sort(candidates.begin(),candidates.end());
        Solve(candidates,0,target,ans,{});
        return ans;
    }
};
