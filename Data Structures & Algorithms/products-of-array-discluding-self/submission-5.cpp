class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>leftPdt(n,1);
        vector<int>rightPdt(n,1);

        for(int i=1;i<n;i++)
        {
            leftPdt[i]=nums[i-1]*leftPdt[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            rightPdt[i]=nums[i+1]*rightPdt[i+1];
        }

        vector<int>ans(n,1);
        for(int i=0;i<n;i++)
        {
            ans[i]=(leftPdt[i]*rightPdt[i]);
        }
        return ans;
    }
};
