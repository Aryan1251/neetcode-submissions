class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int s=0,e=row*col-1;

        while(s<=e)
        {
            int mid=(s+e)>>1;

            int rInd=mid/col;
            int cInd=mid%col;

            if(matrix[rInd][cInd]==target) return 1;
            else if(matrix[rInd][cInd]<target) s=mid+1;
            else e=mid-1;
        }
        return 0;
    }
};
