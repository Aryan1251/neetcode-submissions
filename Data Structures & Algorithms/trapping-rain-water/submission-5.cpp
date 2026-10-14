class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=-1,rightMax=-1,i=0,j=n-1,totalArea=0;
        while(i<=j)
        {
            if(height[i]<height[j])
            {
                if(leftMax>height[i])
                {
                    totalArea+=leftMax-height[i];
                }
                leftMax=max(leftMax,height[i]);
                i++;
            }else
            {
                if(rightMax>height[j])
                {
                    totalArea+=rightMax-height[j];
                }
                rightMax=max(rightMax,height[j]);
                j--;
            }
        }
        return totalArea;
    }
};
