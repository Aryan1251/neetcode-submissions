class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int s=0,e=m*n-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            int rInd=mid/n;
            int cInd=mid%n;
            int element=matrix[rInd][cInd];
            if(element==target) return true;
            else if(element<target) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};
