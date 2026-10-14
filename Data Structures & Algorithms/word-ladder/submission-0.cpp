class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int>mp;
        for(auto str: wordList)
        {
            mp[str]=1;
        }
        if(mp.find(endWord)==mp.end()) return 0;
        queue<pair<string,int> >q;
        q.push({beginWord,0});
        if(mp.find(beginWord)!=mp.end()) mp.erase(beginWord);
        while(!q.empty())
        {
            string str=q.front().first;
            int cnt=q.front().second;
            if(str==endWord) return cnt+1;
            q.pop();
            for(int i=0;i<str.size();i++)
            {
                char currCh=str[i];
                for(int j=0;j<26;j++)
                {
                    char ch=j+'a';
                    str[i]=ch;
                    if(mp.find(str)!=mp.end())
                    {
                        mp.erase(str);
                        q.push({str,cnt+1});
                    }
                }
                str[i]=currCh;
            }
        }
        return 0;
    }
};
