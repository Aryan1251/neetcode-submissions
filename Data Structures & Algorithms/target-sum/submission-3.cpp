class Solution {
    int Solve(vector<int>& nums,map<pair<int,int>,int>& dp,int target,int ind)
    {
        if(ind>=nums.size())
        return target==0?1:0;

        if(dp.find({target,ind})!=dp.end()) return dp[{target,ind}];

        int op1=Solve(nums,dp,target-nums[ind],ind+1);
        int op2=Solve(nums,dp,target+nums[ind],ind+1);

        return dp[{target,ind}]= op1+op2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        map<pair<int,int>,int>dp;
        int ans=Solve(nums,dp,target,0);
        return ans;
    }
};
