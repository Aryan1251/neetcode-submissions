class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i=0,j=heights.size()-1;
        int maxArea=INT_MIN;
        while(i<j)
        {
            if(heights[i]<heights[j])
            {
                int area=heights[i]*(j-i);
                maxArea=max(maxArea,area);
                i++;
            }else
            {
                int area=heights[j]*(j-i);
                maxArea=max(maxArea,area);
                j--;
            }
        }
        return maxArea;
    }
};
