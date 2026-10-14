class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string str;
        for(auto s: strs)
        {
            str+=s;
            str+='1';
            str+='#';
        }
        cout<<str<<" ";
        return str;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        vector<string>v;
        int j=0,index=0;
        while(j<s.size())
        {
            if(s[j]>='0' && s[j]<='9' && s[j+1]=='#')
            {
                string str=s.substr(index,j-index);
                v.push_back(str);
                j+=2;
                index=j;
            }else
            j++;
        }

        return v;
    }
};
