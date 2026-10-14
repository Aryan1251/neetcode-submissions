class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        set<int>st;
        for(auto num: nums)
        st.insert(num);

        int num=*st.begin();
        st.erase(st.begin());

        int len=1,maxLen=1;
        for(auto val: st)
        {
            if(val-1==num) len++;
            else
            {
                maxLen=max(maxLen,len);
                len=1;
            }
            num=val;
        }
        maxLen=max(maxLen,len);
        return maxLen;
    }
};
