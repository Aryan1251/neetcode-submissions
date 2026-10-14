class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0 || s.size()==1) return s.size();
        unordered_map<char,int>mp;
        int l=0,r=0,n=s.size();
        int maxLen=INT_MIN;
        while(r<n)
        {
            mp[s[r]]++;
            while(mp[s[r]]>1)
            {
                mp[s[l]]--;
                if(mp[s[l]]==0)
                mp.erase(s[l]);
                l++;
            }
            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};
