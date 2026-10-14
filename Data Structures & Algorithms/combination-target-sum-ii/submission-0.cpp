class Solution {
    void Solve(vector<int>& nums,int ind,int target,vector<int>v ,vector<vector<int> >& ans)
    {
        if(target==0)
        {
            ans.push_back(v);
            return ;
        }
        if(ind>=nums.size())
        {
            return ;
        }

        for(int i=ind;i<nums.size();i++)
        {
            if(i!=ind && nums[i]==nums[i-1]) continue;
            if(nums[i]<=target)
            {
                v.push_back(nums[i]);
                Solve(nums,i+1,target-nums[i],v,ans);
                v.pop_back();
            }
        }
        return ;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        vector<vector<int> > ans;
        Solve(candidates,0,target,v,ans);
        return ans;
    }
};
