class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP=INT_MIN,pdt=1,n=nums.size();

        for(int i=0;i<n;i++)
        {
            pdt*=nums[i];
            maxP=max(maxP,pdt);
            if(pdt==0) pdt=1;
        }

        pdt=1;
        for(int i=n-1;i>=0;i--)
        {
            pdt*=nums[i];
            maxP=max(maxP,pdt);
            if(pdt==0) pdt=1;
        }

        return maxP;
    }
};
