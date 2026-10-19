class Solution {
    string getIdxString(string str)
    {
        int arr[26]={0};
        string s;
        for(auto ch: str)
        {
            int ind=ch-'a';
            arr[ind]++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]>0) 
            {
                char ch=i+'a';
                int cnt=arr[i];
                while(cnt--)
                {
                    s+=ch;
                }
            }
        }
        return s;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> >mp;

        for(auto str: strs)
        {
            string idx=getIdxString(str);
            mp[idx].push_back(str);
        }

        vector<vector<string> >ans;
        for(auto it: mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
