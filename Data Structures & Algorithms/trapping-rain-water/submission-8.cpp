class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0) return 0;
        vector<int>leftMax(n+1);
        vector<int>rightMax(n+1);
        leftMax[0]=-1;
        int maxi=INT_MIN;
        for(int i=1;i<n;i++)
        {
            maxi=max(leftMax[i-1],height[i-1]);
            if(maxi>height[i]) leftMax[i]=maxi;
            else leftMax[i]=-1;
        }

        maxi=INT_MIN;
        rightMax[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            maxi=max(rightMax[i+1],height[i+1]);
            if(maxi>height[i]) rightMax[i]=maxi;
            else rightMax[i]=-1;
        }
        
        int i=0,ans=0;
        while(i<n)
        {
            if(leftMax[i]!=-1 && rightMax[i]!=-1)
            {
                ans+=min(leftMax[i],rightMax[i])-height[i];
                i++;
            }else i++;
        }
        return ans;
    }
};
