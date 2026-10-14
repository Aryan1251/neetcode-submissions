class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n),right(n);
        left[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            left[i]=min(left[i-1],nums[i]);
        }
        right[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],nums[i]);
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            res=max(res,right[i]-left[i]);
        }
        return res;
    }
};
