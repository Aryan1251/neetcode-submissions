class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>leftMax(n,-1),rightMax(n,-1);
        int maxi=-1;
        for(int i=1;i<n;i++)
        {
            maxi=max(maxi,height[i-1]);
            if(height[i]<maxi)
            leftMax[i]=maxi;
            else leftMax[i]=-1;
        }
        maxi=-1;
        for(int i=n-2;i>=0;i--)
        {
            maxi=max(maxi,height[i+1]);
            if(maxi>height[i])
            rightMax[i]=maxi;
            else rightMax[i]=-1;
        }

        int totalWaterCollect=0;
        for(int i=0;i<n;i++)
        {
            if(leftMax[i]==-1 || rightMax[i]==-1) continue;
            else
            {
                totalWaterCollect+=abs(height[i]-min(leftMax[i],rightMax[i]));
            }
        }
        return totalWaterCollect;
    }
};
