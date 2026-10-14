class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int res=0,minBuy=nums[0];
        for(int i=0;i<n;i++)
        {
            res=max(res,nums[i]-minBuy);
            minBuy=min(minBuy,nums[i]);
        }
        return res;
    }
};
