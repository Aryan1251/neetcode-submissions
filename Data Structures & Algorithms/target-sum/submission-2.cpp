class Solution {
    int Solve(vector<int>& nums,int target,int ind,map<pair<int,int>,int>& dp)
    {
        if(ind>=nums.size())
        {
            return target==0?1:0;
        }
        if(dp.find({target,ind})!=dp.end()) return dp[{target,ind}];

        int op1=Solve(nums,target-nums[ind],ind+1,dp);
        int op2=Solve(nums,target+nums[ind],ind+1,dp);

        return dp[{target,ind}]= op1+op2;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        map<pair<int,int>,int >dp;
        int ans=Solve(nums,target,0,dp);
        return ans;
    }
};
