class Solution {
    private:
    void Solve(vector<int> nums,int target,int index,vector<int>v,vector<vector<int> >& ans)
    {
        if(target==0)
        {
            ans.push_back(v);
            return ;
        }
        if(index>=nums.size())
        {
            return ;
        }

        if(nums[index]<=target)
        {
            v.push_back(nums[index]);
            Solve(nums,target-nums[index],index,v,ans);
            v.pop_back();
        }
        Solve(nums,target,index+1,v,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>v;
        vector<vector<int> >ans;
        Solve(nums,target,0,v,ans);
        return ans;
    }
};
