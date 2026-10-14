class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        set<int>st;
        for(auto it:triplets)
        {
            if(it[0]>target[0] || it[1]>target[1] || it[2]>target[2]) continue;
            for(int i=0;i<it.size();i++)
            {
                if(it[i]==target[i])
                st.insert(i);
            }
        }
        return st.size()==3;
    }
};
