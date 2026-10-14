class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int >mp;
        for(auto ch: t)
        {
            mp[ch]++;
        }
        int i=0,j=0,cnt=0;
        string str;
        while(j<s.size())
        {
            if(mp.find(s[j])!=mp.end())
            {
                if(mp[s[j]]>0)
                {
                    mp[s[j]]--;
                    cnt++;
                }else
                mp[s[j]]--;
            }
            else
            mp[s[j]]--;
            while(cnt==t.size())
            {
                mp[s[i]]++;
                if(mp[s[i]]>0)
                {
                    break;
                }
                i++;
            }
            if(cnt==t.size())
            {
                str=s.substr(i,j-i+1);
                cnt--;
                i++;
            }
            j++;
        }

        return str;
    }
};
