class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int>st;
        for(auto num: nums)
        st.insert(num);

        int val=*st.begin();
        int maxLen=1,len=1;
        for(auto it: st)
        {
            int num=it;
            if(num-1==val)
            {
                len++;
                val=num;
                maxLen=max(maxLen,len);
            }
            else
            {
                val=num;
                len=1;
            }
        }
        return maxLen;
        
    }
};
