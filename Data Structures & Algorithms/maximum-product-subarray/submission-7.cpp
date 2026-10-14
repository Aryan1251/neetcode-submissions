class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct=INT_MIN;
        int n=nums.size();
        int pdt=1;
        for(int i=0;i<n;i++)
        {
            pdt*=nums[i];
            maxProduct=max(maxProduct,pdt);
            if(pdt==0) pdt=1;
        }
        pdt=1;
        for(int i=n-1;i>=0;i--)
        {
            pdt*=nums[i];
            maxProduct=max(maxProduct,pdt);
            if(pdt==0) pdt=1;
        }
        return maxProduct;
    }
};
