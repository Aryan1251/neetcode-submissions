class Solution {
    int Solve(vector<int>& nums,int index)
    {
        if(index>=nums.size()-1) return 0;

        int ans=INT_MAX;
        for(int i=1;i<=nums[index];i++)
        {
            int op1=Solve(nums,i+index);
            if(op1!=INT_MAX) op1+=1;
            ans=min(ans,op1);
        }
        return ans;
    }
    int solveTab(vector<int>& nums)
    {
        vector<int>dp(nums.size()+1,0);
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1) continue;
            int ans=INT_MAX;
            for(int j=1;j<=nums[i];j++)
            {
                int op1=dp[j+i];// Solve(nums,i+index);
                if(op1!=INT_MAX) op1+=1;
                ans=min(ans,op1);
            }
            dp[i]= ans;
        }
        return dp[0];
    }
public:
    int jump(vector<int>& nums) {
        return solveTab(nums);
    }
};
