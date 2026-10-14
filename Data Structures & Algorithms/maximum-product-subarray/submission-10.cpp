class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pdt=1,maxi=INT_MIN,n=nums.size();
        for(int i=0;i<n;i++)
        {
            pdt*=nums[i];
            maxi=max(maxi,pdt);
            if(pdt==0) pdt=1;
        }
        pdt=1;
        for(int i=n-1;i>=0;i--)
        {
            pdt*=nums[i];
            maxi=max(maxi,pdt);
            if(pdt==0) pdt=1;
        }
        return maxi;
    }
};
