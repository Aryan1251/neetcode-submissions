class Solution {
    int Solve(vector<int>& nums,int target,int ind)
    {
        if(ind>=nums.size())
        {
            return target==0?1:0;
        }

        int op1=Solve(nums,target-nums[ind],ind+1);
        int op2=Solve(nums,target+nums[ind],ind+1);

        return op1+op2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=Solve(nums,target,0);
        return ans;
    }
};
