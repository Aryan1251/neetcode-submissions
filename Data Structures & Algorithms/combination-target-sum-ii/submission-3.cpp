class Solution {
    void Solve(vector<int>& arr,vector<vector<int> >& ans,vector<int>& v,int ind,int target)
    {
        if(target==0)
        {
            ans.push_back(v);
            return ;
        }
        if(ind>=arr.size()) return ;

        for(int i=ind;i<arr.size();i++)
        {
            if(i!=ind && arr[i]==arr[i-1]) continue;
            if(arr[i]<=target)
            {
                v.push_back(arr[i]);
                Solve(arr,ans,v,i+1,target-arr[i]);
                v.pop_back();
            }else break;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>v;
        vector<vector<int> >ans;
        sort(candidates.begin(),candidates.end());
        Solve(candidates,ans,v,0,target);
        return ans;
    }
};
