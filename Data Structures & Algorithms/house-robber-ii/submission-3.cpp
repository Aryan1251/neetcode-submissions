#include<bits/stdc++.h>

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
        if(nums.size()==1) return nums[0];
        int n=nums.size();
        vector<int>nums2,nums1;

        for(int i=0;i<n-1;i++) nums1.push_back(nums[i]);

        for(int i=1;i<n;i++) nums2.push_back(nums[i]);

        vector<int>dp(n,-1);
        int op1=Solve(nums1,dp,0);
        dp.clear();

        for(int i=0;i<n;i++) dp[i]=-1;

        int op2=Solve(nums2,dp,0);

        return max(op1,op2);

    }
};
