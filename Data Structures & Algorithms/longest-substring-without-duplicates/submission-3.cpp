class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int maxLen=0,left=0,right=0,n=s.size();

        while(right<n)
        {
            while(left<right && mp.find(s[right])!=mp.end())
            {
                mp[s[left]]--;
                if(mp[s[left]]==0) mp.erase(s[left]);
                left++;
            }
            mp[s[right]]++;
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};
