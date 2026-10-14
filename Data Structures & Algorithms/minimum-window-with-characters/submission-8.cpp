class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        for(auto ch: t)
        mp[ch]--;

        int i=0,j=0,cnt=0,minLen=INT_MAX,st=-1,n=s.size();
        while(j<n)
        {
            if(mp[s[j]]<0) cnt++;
            mp[s[j]]++;
            
            while(cnt==t.size())
            {
                if(minLen>j-i+1)
                {
                    minLen=j-i+1;
                    st=i;
                }
                if(mp[s[i]]==0) cnt--;
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            j++;
        }
        if(st==-1) return "";
        string ans=s.substr(st,minLen);
        return ans;
    }
};
