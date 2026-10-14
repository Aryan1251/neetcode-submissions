class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0,j=n-1,maxArea=INT_MIN;
        while(i<j)
        {
            maxArea=max(maxArea,min(heights[j],heights[i])*(j-i));
            if(heights[i]<heights[j])
            {
                i++;
            }else
            j--;
        }
        return maxArea;
    }
};
