class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int> >pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        int n=nums.size();
        for(int i=0;i<n && i<k;i++)
        {
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++)
        {
            if(!pq.empty() && nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<K || pq.empty())
        {
            pq.push(val);
            return pq.top();
        }
        if(val>pq.top())
        {
            pq.pop();
            pq.push(val);
            return pq.top();
        }else
        return pq.top();
    }
};
