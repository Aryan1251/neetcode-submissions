class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int> >pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i=0;i<k && i<nums.size();i++)
        pq.push(nums[i]);

        for(int i=k;i<nums.size();i++)
        {
            if(!pq.empty() && nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<K)
        {
            pq.push(val);
            return pq.top();
        }
        if(!pq.empty() && val>pq.top())
        {
            pq.pop();
            pq.push(val);
            return pq.top();
        }
        if(!pq.empty())
        return pq.top();

        pq.push(val);
        return pq.top();
    }
};
