class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pdt=1;
        int maxPdt=INT_MIN;
        for(int i=0;i<n;i++)
        {
            pdt*=nums[i];
            maxPdt=max(maxPdt,max(nums[i],pdt));
        }
        pdt=1;
        for(int i=n-1;i>=0;i--)
        {
            pdt*=nums[i];
            maxPdt=max(maxPdt,pdt);
        }
        return maxPdt;
    }
};
