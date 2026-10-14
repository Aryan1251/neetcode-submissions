class Solution {
    void Solve(vector<int>& nums,vector<vector<int> >& ans,int target,vector<int>v,int index)
    {
        if(index>=nums.size())
        {
            if(target==0)
            ans.push_back(v);
            return ;
        }

        if(nums[index]<=target)
        {
            v.push_back(nums[index]);
            Solve(nums,ans,target-nums[index],v,index);
            v.pop_back();
        }
        Solve(nums,ans,target,v,index+1);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int> >ans;
        vector<int>v;
        Solve(nums,ans,target,v,0);
        return ans;
    }
};
