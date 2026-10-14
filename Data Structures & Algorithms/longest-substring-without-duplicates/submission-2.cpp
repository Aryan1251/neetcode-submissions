class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int len=0,maxLen=0,l=0,r=0;
        while(r<s.size())
        {
            if(mp.find(s[r])==mp.end())
            {
                mp[s[r]]++;
                r++;
                len++;
                maxLen=max(maxLen,len);
            }
            else{
                maxLen=max(maxLen,len);
                while(l<=r && mp.find(s[r])!=mp.end())
                {
                    mp[s[l]]--;
                    if(mp[s[l]]==0) mp.erase(s[l]);
                    l++;
                    len--;
                }
                mp[s[r]]++;
                len++;
                r++;
            }
        }
        return maxLen;
    }
};
