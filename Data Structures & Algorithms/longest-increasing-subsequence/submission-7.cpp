class Solution {
    int Solve(vector<int>& nums,map<pair<int,int>,int>& dp,int prev,int ind)
    {
        if(ind>=nums.size()) return 0;
        if(dp.find({prev,ind})!=dp.end()) return dp[{prev,ind}];

        int op1=0,op2=0;
        if(nums[ind]>prev) 
        op1=1+Solve(nums,dp,nums[ind],ind+1);

        op2=Solve(nums,dp,prev,ind+1);

        return dp[{prev,ind}]= max(op2,op1);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        map<pair<int,int>,int>dp;
        int ans=Solve(nums,dp,INT_MIN,0);
        return ans;
    }
};
