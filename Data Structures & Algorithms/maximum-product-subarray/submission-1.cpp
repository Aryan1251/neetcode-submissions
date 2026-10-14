class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN,pdt=1,n=nums.size();
        for(int i=0;i<n;i++)
        {
            pdt*=nums[i];
            maxi=max(pdt,maxi);
            maxi=max(maxi,nums[i]);
        }
        pdt=1;
        for(int i=n-1;i>=0;i--)
        {
            pdt*=nums[i];
            maxi=max(pdt,maxi);
            maxi=max(maxi,nums[i]);
        }
        return maxi;
    }
};
