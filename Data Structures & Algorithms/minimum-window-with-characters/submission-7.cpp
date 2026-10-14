class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int minLen=INT_MAX;
        for(auto ch: t) mp[ch]--;

        int startIndex=0,k=t.size();
        int i=0,j=0,cnt=0,n=s.size();
        while(j<n)
        {
            if(mp[s[j]]<0) cnt++;
            mp[s[j]]++;
            while(cnt==k)
            {
                if(j-i+1<minLen) {
                    minLen=j-i+1;
                    startIndex=i;
                }
                mp[s[i]]--;
                if(mp[s[i]]<0) cnt--;
                i++;
            }
            j++;
        }
        if(minLen==INT_MAX) return "";
        string str=s.substr(startIndex,minLen);
        return str;

    }
};
