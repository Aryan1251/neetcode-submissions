class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxIdx=0;
        for(int i=0;i<n;i++)
        {
            if(i<=maxIdx)
            {
                int idx=i+nums[i];
                maxIdx=max(maxIdx,idx);
                if(idx>=n-1) return true;
            }else return false;
        }
        return true;
    }
};
