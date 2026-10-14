class Solution {
    vector<int> prevSmallest(vector<int>& arr)
    {
        stack<int>st;
        vector<int>v;
        st.push(-1);
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top()!=-1 && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            v.push_back(st.top());
            st.push(i);
        }
        return v;
    }
    vector<int> nextSmallest(vector<int>& arr)
    {
        stack<int>st;
        vector<int>v;
        st.push(-1);
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top()!=-1 && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            v.push_back(st.top());
            st.push(i);
        }
        reverse(v.begin(),v.end());
        return v;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>prev=prevSmallest(heights);
        vector<int>next=nextSmallest(heights);

        int area=INT_MIN,n=heights.size();
        for(int i=0;i<n;i++)
        {
            if(next[i]==-1) next[i]=n;
            int bre=next[i]-prev[i]-1;
            int len=heights[i];
            area=max(area,bre*len);
        }
        return area;
    }
};
