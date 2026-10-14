class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>v(3,1);
        int n=triplets.size();
        for(int i=0;i<n;i++)
        {
            auto& arr=triplets[i];
            int ind=1;
            for(int i=0;i<3;i++)
            {
                if(arr[i]>target[i]){
                    ind=0;
                    break;
                }
            }
            if(ind==1)
            {
                for(int i=0;i<3;i++)
                v[i]=max(arr[i],v[i]);
            }
        }
        return v==target;
    }
};
