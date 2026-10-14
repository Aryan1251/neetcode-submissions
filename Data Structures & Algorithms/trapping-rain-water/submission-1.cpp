class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int i=0,j=n-1,leftMax=-1,rightMax=-1;
        int water=0;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                if(leftMax>height[i])
                {
                    water+=(leftMax-height[i]);
                }
                leftMax=max(leftMax,height[i]);
                i++;
            }else
            {
                if(rightMax>height[j])
                {
                    water+=(rightMax-height[j]);
                }
                rightMax=max(rightMax,height[j]);
                j--;
            }
        }
        return water;
    }
};
