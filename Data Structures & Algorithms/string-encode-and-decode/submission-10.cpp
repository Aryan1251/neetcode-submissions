class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(auto str:strs)
        {
            s+=str;
            s+=1+'0';
            s+='#';
        }
        cout<<s<<" ";
        return s;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        int index=0;
        vector<string>ans;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]>='0' && s[i]<='9' && s[i+1]=='#')
            {
                string str=s.substr(index,i-index);
                ans.push_back(str);
                i++;
                index=i+1;
            }
        }
        return ans;
    }
};
