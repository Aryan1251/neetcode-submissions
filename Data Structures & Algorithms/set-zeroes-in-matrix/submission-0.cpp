class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>rowInd;
        vector<int>colInd;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    rowInd.push_back(i);
                    colInd.push_back(j);
                }
            }
        }
        for(int row=0;row<rowInd.size();row++)
        {
            for(int col=0;col<m;col++)
            {
                matrix[rowInd[row]][col]=0;
            }
        }
        for(int col=0;col<colInd.size();col++)
        {
            for(int row=0;row<n;row++)
            {
                matrix[row][colInd[col]]=0;
            }
        }
    }
};
