class Solution {
    void Solve(vector<int>& nums,int target,int index,vector<vector<int> >& ans,vector<int>v)
    {
        if(target==0)
        {
            ans.push_back(v);
            return ;
        }
        if(index>=nums.size()) return ;

        if(target>=nums[index])
        {
            v.push_back(nums[index]);
            Solve(nums,target-nums[index],index,ans,v);
            v.pop_back();
        }

        Solve(nums,target,index+1,ans,v);
        
        return ;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int> >ans;
        Solve(nums,target,0,ans,{});
        return ans;
    }
};
