class WordDictionary {
public:
    unordered_map<string,int>mp;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word]=1;
    }
    
    bool search(string word) {
        if(mp.find(word)!=mp.end()) return true;
        for(auto it: mp)
        {
            string s=it.first;
            if(s.size()!=word.size()) continue;
            int i=0,j=0,flag=1;
            while(i<s.size() && j<word.size())
            {
                if(word[j]=='.') 
                {
                    i++;
                    j++;
                }else if(s[i]==word[j])
                {
                    i++;
                    j++;
                }else
                {
                    flag=0;
                    break;
                }
            }
            if(flag) return true;
        }
    }
};
