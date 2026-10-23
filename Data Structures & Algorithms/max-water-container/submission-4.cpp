class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0,j=n-1;
        int maxArea=INT_MIN;
        while(i<j)
        {
            int area=min(heights[i],heights[j])*(j-i);
            maxArea=max(maxArea,area);
            if(heights[i]<heights[j]) i++;
            else j--;
        }
        return maxArea;
    }
};
