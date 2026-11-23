class Solution {
    bool Solve(vector<int>& nums,vector<vector<int> >& dp,int target,int ind)
    {
        if(target==0) return 1;
        if(ind>=nums.size()) return 0;
        if(dp[target][ind]!=-1) return dp[target][ind];

        bool op1=false;
        if(nums[ind]<=target)
        op1=Solve(nums,dp,target-nums[ind],ind+1);

        bool op2=Solve(nums,dp,target,ind+1);

        return dp[target][ind]= op1|op2;
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++)
        sum+=nums[i];

        if(sum%2!=0) return false;
        vector<vector<int> >dp((sum/2+1),vector<int>(n+1,-1));
        return Solve(nums,dp,sum/2,0);
    }
};
