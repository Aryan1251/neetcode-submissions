class Solution {
    int Solve(vector<int>& nums,int index,vector<int>& dp)
    {
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];

        int op1=nums[index]+Solve(nums,index+2,dp);
        int op2=Solve(nums,index+1,dp);

        return dp[index]=max(op2,op1);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        int ans=Solve(nums,0,dp);
        return ans;
    }
};
