class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        vector<int>ans;
        int maxCnt=0;
        for(auto num: nums)
        {
            mp[num]++;
            maxCnt=max(maxCnt,mp[num]);
        }
        for(int i=maxCnt;i>=0;i--)
        {
            for(auto it: mp)
            {
                if(it.second==i) ans.push_back(it.first);
                if(ans.size()==k) return ans;
            }
        }
        return {};
    }
};
