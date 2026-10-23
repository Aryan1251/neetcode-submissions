class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;
        for(auto str: strs)
        {
            encoded_string+=str;
            encoded_string+='1';
            encoded_string+='#';
        }
        // cout<<encoded_string<<endl;
        return encoded_string;
    }

    vector<string> decode(string s) {
        int i=0,j=0,n=s.size();
        vector<string>ans;
        while(j<n)
        {
            if(s[j]=='1' && j+1<n && s[j+1]=='#')
            {
                string str=s.substr(i,j-i);
                ans.push_back(str);
                j+=2;
                i=j;
            }else
            j++;
        }return ans;
    }
};
