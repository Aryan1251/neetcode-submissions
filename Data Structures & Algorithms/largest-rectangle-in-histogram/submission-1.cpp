class Solution {
    vector<int> prevSmallest(vector<int>& arr)
    {
        stack<int>st;
        st.push(-1);
        vector<int>ans;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()!=-1 && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmallest(vector<int>& arr)
    {
        stack<int>st;
        st.push(-1);
        vector<int>ans;
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()!=-1 && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left=prevSmallest(heights);
        vector<int>right=nextSmallest(heights);
        int maxArea=0;
        for(int i=0;i<n;i++)
        {
            if(right[i]==-1) right[i]=n;
            int width=right[i]-left[i]-1;
            int area=width*heights[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};
