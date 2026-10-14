class Solution {
    bool Solve(vector<int>& nums,int index,int sum,vector<vector<int> >& dp)
    {
        if(sum==0) return true;
        if(index>=nums.size()) return false;
        if(dp[index][sum]!=-1) return dp[index][sum];

        bool op1=false;
        if(nums[index]<=sum)
        op1=Solve(nums,index+1,sum-nums[index],dp);

        bool op2=Solve(nums,index+1,sum,dp);

        return dp[index][sum]=op1|op2;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        vector<vector<int> >dp(n+1,vector<int>((sum/2)+1,-1));
        bool ans=Solve(nums,0,sum/2,dp);
        return ans;
    }
};
