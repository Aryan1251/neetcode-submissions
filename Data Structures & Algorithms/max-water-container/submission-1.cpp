class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0,j=n-1;
        int maxArea=0;
        while(i<j)
        {
            if(heights[i]<heights[j])
            {
                int len=j-i;
                maxArea=max(maxArea,len*heights[i]);
                i++;
            }else
            {
                int len=j-i;
                maxArea=max(maxArea,len*heights[j]);
                j--;
            }
        }
        return maxArea;
    }
};
