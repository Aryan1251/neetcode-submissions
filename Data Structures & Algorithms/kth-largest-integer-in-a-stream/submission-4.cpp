class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int> >pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K=k;
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
    }
    
    int add(int val) {
        if(pq.size()<K)
        {
            pq.push(val);
            return pq.top();
        }
        if(pq.top()<val)
        {
            pq.pop();
            pq.push(val);
            return pq.top();
        }
        return pq.top();
    }
};
