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
        vector<string>strs;
        int strInd=0;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='#' && s[i+1]=='1')
            {
                string str=s.substr(strInd,i-strInd);
                strs.push_back(str);
                strInd=i+2;
            }
        }
        return strs;
    }
};
