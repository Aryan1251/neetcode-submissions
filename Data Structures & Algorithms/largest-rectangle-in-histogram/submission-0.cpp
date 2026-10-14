class Solution {
    private:
    vector<int> prevSmallest(vector<int>& arr)
    {
        stack<int>st;
        vector<int>v(arr.size());
        st.push(-1);
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            while(st.top()!=-1 && !st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> nextSmallest(vector<int>& arr)
    {
        stack<int>st;
        vector<int>v(arr.size());
        st.push(-1);
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!=-1 && !st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev=prevSmallest(heights);
        vector<int>next=nextSmallest(heights);
        int maxArea=0;
        int n=heights.size();
        for(int i=0;i<n;i++)
        {
            int len=heights[i];
            if(next[i]==-1)
            next[i]=n;
            int bre=next[i]-prev[i]-1;
            maxArea=max(maxArea,len*bre);
        }
        return maxArea;
    }
};
