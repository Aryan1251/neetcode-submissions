class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string s;
        for(auto str: strs)
        {
            s+=str;
            s+='#';
            s+='1';
        }
        return s;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<string> ans;
        int stInd=0,i=0,n=s.size();
        while(i<n)
        {
            if(s[i]=='#' && s[i+1]=='1')
            {
                ans.push_back(s.substr(stInd,i-stInd));
                i+=2;
                stInd=i;
            }else
            i++;
        }
        return ans;
    }
};
