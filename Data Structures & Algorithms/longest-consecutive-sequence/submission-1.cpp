class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>st;
        for(auto num: nums)
        {
            st.insert(num);
        }
        unordered_map<int,int>mp;
        for(auto num: st)
        {
            if(mp.find(num-1)!=mp.end())
            {
                mp[num]+=mp[num-1]+1;
            }
            else
            mp[num]=1;
        }
        int res=0;
        for(auto it: mp)
        {
            res=max(res,it.second);
        }

        return res;
    }
};
