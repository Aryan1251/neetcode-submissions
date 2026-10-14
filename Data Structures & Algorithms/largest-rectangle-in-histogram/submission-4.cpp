class Solution {
    vector<int> solveLeft(vector<int>& heights)
    {
        stack<int>st;
        vector<int>ans;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    vector<int> solveRight(vector<int>& heights)
    {
        stack<int>st;
        vector<int>ans;
        int n=heights.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>leftArr=solveLeft(heights);
        vector<int>rightArr=solveRight(heights);
        
        int n=heights.size();
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            int a=leftArr[i];
            int b=(rightArr[i]==-1) ? n : rightArr[i];
            int bre=b-a-1;
            int h=heights[i];
            int area=bre*h;
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};
