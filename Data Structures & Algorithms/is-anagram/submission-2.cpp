class Solution {
    bool chkAnagram(string &s,string &t)
    {
        int hash[26]={0};
        for(auto ch: s)
        {
            int index=ch-'a';
            hash[index]++;
        }
        for(auto ch: t)
        {
            int index=ch-'a';
            hash[index]--;
        }
        for(int i=0;i<26;i++)
        {
            if(hash[i]!=0) return 0;
        }
        return 1;
    }
public:
    bool isAnagram(string s, string t) {
        bool ans=chkAnagram(s,t);
        return ans;
    }
};
