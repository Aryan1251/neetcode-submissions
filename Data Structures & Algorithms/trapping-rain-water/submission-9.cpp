class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0 || n==1) return 0;
        
        int leftMax=-1,rightMax=-1,left=0,right=n-1,ans=0;
        while(left<=right)
        {
            if(height[left]<height[right])
            {
                if(leftMax>height[left])
                {
                    ans+=leftMax-height[left];
                }
                leftMax=max(leftMax,height[left]);
                left++;
            }else
            {
                if(rightMax>height[right])
                {
                    ans+=rightMax-height[right];
                }
                rightMax=max(rightMax,height[right]);
                right--;
            }
        }
        return ans;
    }
};
