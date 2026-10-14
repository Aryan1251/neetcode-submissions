class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        int n=nums.size();
        for(int i=0;i<k && i<n;i++)
        {
            if(dq.empty()) dq.push_back(i);
            else
            {
                while(!dq.empty() && nums[dq.back()]<=nums[i])
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        vector<int>ans;
        for(int i=k;i<n;i++)
        {
            ans.push_back(nums[dq.front()]);
            while(!dq.empty() && i-dq.front()>=k)
            {
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        } 
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};
