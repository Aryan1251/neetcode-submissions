class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=0,rightMax=0,left=0,right=n-1,res=0;

        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(leftMax>height[left])
                {
                    res+=leftMax-height[left];
                }else leftMax=max(leftMax,height[left]);
                left++;
            }else
            {
                if(rightMax>height[right])
                {
                    res+=rightMax-height[right];
                }else rightMax=max(rightMax,height[right]);
                right--;
            }
        }
        return res;
    }
};
