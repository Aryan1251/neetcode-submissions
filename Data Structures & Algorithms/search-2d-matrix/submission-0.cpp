class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int s=0,e=n*m-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;
            int rowInd=mid/m;
            int colInd=mid%m;
            int val=matrix[rowInd][colInd];
            if(val==target) return true;
            else if(val<target) s=mid+1;
            else e=mid-1;
        }
        return false;
    }
};
