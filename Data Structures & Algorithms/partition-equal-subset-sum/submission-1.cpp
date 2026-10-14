class Solution {
    bool Solve(vector<int>& nums,int ind,int target,vector<vector<int> >& dp)
    {
        if(target==0) return 1;
        if(ind>=nums.size()) return 0;
        if(dp[ind][target]!=-1) return dp[ind][target];


        bool op1=false;
        if(nums[ind]<=target)
        op1=Solve(nums,ind+1,target-nums[ind],dp);

        bool op2=Solve(nums,ind+1,target,dp);

        return dp[ind][target]= op1||op2;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        if(sum&1) return 0;

        int target=sum/2;
        vector<vector<int> >dp(nums.size()+1,vector<int>(target+1,-1));
        bool ans=Solve(nums,0,target,dp);
        return ans;
    }
};
