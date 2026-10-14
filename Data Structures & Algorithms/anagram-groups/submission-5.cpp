class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> >mp;
        vector<vector<string> >ans;
        for(auto str: strs)
        {
            int count[26]={0};
            for(auto ch:str)
            {
                int index=ch-'a';
                count[index]++;
            }
            string s;
            for(int i=0;i<26;i++)
            {
                s+=to_string(count[i]);
                s+=',';
            }
            mp[s].push_back(str);
        }
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
