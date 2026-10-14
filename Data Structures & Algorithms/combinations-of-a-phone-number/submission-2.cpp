class Solution {
    void Solve(string digits,int index,unordered_map<int,string>& mp,string s,vector<string>& ans)
    {
        if(index>=digits.size())
        {
            ans.push_back(s);
            return ;
        }

        string str=mp[digits[index]-'0'];
        for(int i=0;i<str.size();i++)
        {
            s.push_back(str[i]);
            Solve(digits,index+1,mp,s,ans);
            s.pop_back();
        }
        return ;
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"}
        ,{9,"wxyz"}};

        vector<string> ans;
        string s;
        Solve(digits,0,mp,s,ans);
        return ans;
    }
};
