class Solution {
    void Solve(string& digits,unordered_map<int,string>& mp,vector<string>& ans,string s,int ind)
    {
        if(ind>=digits.size())
        {
            ans.push_back(s);
            return ;
        }

        string str=mp[digits[ind]-'0'];
        for(int i=0;i<str.size();i++)
        {
            s.push_back(str[i]);
            Solve(digits,mp,ans,s,ind+1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        
        unordered_map<int,string>mp{{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},
        {6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};

        vector<string>ans;
        string s;
        Solve(digits,mp,ans,s,0);

        return ans;
    }
};
