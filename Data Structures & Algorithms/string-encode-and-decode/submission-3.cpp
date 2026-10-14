class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string s;
        for(auto str: strs)
        {
            int len=str.size();
            if(len>=10)
            s+='9';
            else s+=len+'0';
            s+='#';
            s+=str;
        }
        return s;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        //cout<<s<<endl;
        vector<string>strs;
        int index=1,i=1;
        for(i=1;i<s.size()-1;i++)
        {
            if(s[i]>='0' && s[i]<='9' && s[i+1]=='#')
            {
                string str=s.substr(index+1,(i-index-1));
                strs.push_back(str);
                index=i+1;
            }
        }
        string str=s.substr(index+1,(i-index));
        strs.push_back(str);
        return strs;
    }
};
