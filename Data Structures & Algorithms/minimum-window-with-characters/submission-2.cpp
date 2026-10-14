class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto ch:t)
        {
            mp[ch]++;
        }
        int cnt=0,l=0,r=0,startInd=l;
        int minLen=INT_MAX;
        while(r<s.size())
        {
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;

            while(cnt==t.size())
            {
                minLen=min(minLen,r-l+1);
                startInd=l;
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        if(minLen==INT_MAX) return "";
        return s.substr(startInd,minLen);
    }
};
