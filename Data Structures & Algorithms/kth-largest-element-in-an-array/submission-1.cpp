class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> >pq;
        for(int i=0;i<k && i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        int i=k;
        while(!pq.empty() && i<nums.size())
        {
            if(pq.top()<nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
        return pq.top();
    }
};
