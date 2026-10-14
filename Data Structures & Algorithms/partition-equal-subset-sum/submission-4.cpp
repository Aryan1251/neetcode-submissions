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
    int solveTab(vector<int>& nums,int target)
    {
        int n=nums.size();
        vector<vector<int> >dp(n+1,vector<int>(target+1,-1));

        for(int i=0;i<=n;i++)
        dp[i][0]=1;

        for(int j=0;j<=target;j++)
        dp[n][j]=0;

        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<=target;j++)
            {
                if(i==n || j==0) continue;
                bool op1=false;

                if(nums[i]<=j)
                op1=dp[i+1][j-nums[i]]; //Solve(nums,index+1,sum-nums[index],dp);
                
                bool op2=dp[i+1][j]; //Solve(nums,index+1,sum,dp);
                dp[i][j]=op1|op2;
            }
        }
        return dp[0][target];
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
        bool ans=solveTab(nums,sum/2);
        return ans;
    }
};
