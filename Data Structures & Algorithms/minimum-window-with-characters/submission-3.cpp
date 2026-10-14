class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto ch: t)
        {
            mp[ch]++;
        }
        int l=0,r=0;
        int index=l,cnt=0;
        int minLen=INT_MAX;
        while(r<s.size())
        {
            if(mp[s[r]]>0)
            {
                cnt++;
            }
            mp[s[r]]--;
            while(cnt==t.size())
            {
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                if(minLen>r-l+1)
                {
                    minLen=r-l+1;
                    index=l;
                }
                l++;
            }
            r++;
        }
        if(minLen==INT_MAX) return "";
        return s.substr(index,minLen);
    }
};
