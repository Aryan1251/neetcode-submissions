class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=0,rightMax=0;
        int left=0,right=n-1,area=0;
        while(left<right)
        {
            if(height[left]<=height[right])
            {
                if(leftMax>height[left])
                {
                    area+=leftMax-height[left];
                }
                leftMax=max(leftMax,height[left]);
                left++;
            }else
            {
                if(rightMax>height[right])
                {
                    area+=rightMax-height[right];
                }
                rightMax=max(rightMax,height[right]);
                right--;
            }
        }
        return area;
    }
};
