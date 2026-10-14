class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto ch: t)
        {
            mp[ch]++;
        }
        int n=mp.size();
        int l=0,r=0,cnt=0,minLen=INT_MAX,index=-1;
        while(r<s.size())
        {
            mp[s[r]]--;
            if(mp[s[r]]==0) cnt++;
            while(l<=r && cnt==n)
            {
                if(minLen>r-l+1)
                {
                    minLen=r-l+1;
                    index=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        if(minLen==INT_MAX) return "";
        string str=s.substr(index,minLen);
        return str;
    }
};
