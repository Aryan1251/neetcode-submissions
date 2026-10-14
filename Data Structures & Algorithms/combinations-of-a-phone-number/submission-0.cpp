class Solution {
    private:
    void Solve(string digits,int index,map<int,string >& mp,string str,vector<string>& ans)
    {
        if(index>=digits.size())
        {
            ans.push_back(str);
            return ;
        }

        int num=digits[index]-'0';
        string s=mp[num];
        for(int i=0;i<s.size();i++)
        {
            str+=s[i];
            Solve(digits,index+1,mp,str,ans);
            str.pop_back();
        }
        return ;
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        map<int,string>mp={{2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},
        {9,"wxyz"}};
        vector<string>ans;
        string str;
        Solve(digits,0,mp,str,ans);
        return ans;
    }
};
