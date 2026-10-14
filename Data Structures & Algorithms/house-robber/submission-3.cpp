class Solution {
    int Solve(vector<int>& nums,vector<int>& dp,int ind)
    {
        if(ind>=nums.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int op1=nums[ind]+Solve(nums,dp,ind+2);
        int op2=Solve(nums,dp,ind+1);
        return dp[ind]= max(op1,op2);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans=Solve(nums,dp,0);
        return ans;
    }
};
