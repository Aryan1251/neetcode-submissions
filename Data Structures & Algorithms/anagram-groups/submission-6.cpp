class Solution {
    string mappString(string s)
    {
        int hash[26]={0};
        for(auto ch: s)
        {
            int index=ch-'a';
            hash[index]++;
        }
        string str;
        for(int i=0;i<26;i++)
        {
            int cnt=hash[i];
            while(cnt--)
            {
                str+=i+'a';
            }
        }
        return str;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string> >mp;
        vector<vector<string> >ans;
        for(auto str: strs){
            string s=mappString(str);
            mp[s].push_back(str);
        }

        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }

};
