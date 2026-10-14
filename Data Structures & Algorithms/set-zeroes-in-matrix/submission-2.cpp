class Solution {
    private:
    void SolveRow(vector<vector<int> >& matrix,int i)
    {
        int m=matrix[0].size();
        for(int col=0;col<m;col++)
        {
            if(matrix[i][col]==0) continue;
            matrix[i][col]=-1;
        }
    }
    void SolveCol(vector<vector<int> >& matrix,int j)
    {
        int n=matrix.size();
        for(int row=0;row<n;row++)
        {
            if(matrix[row][j]==0) continue;
            matrix[row][j]=-1;
        }
    }
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
                    SolveRow(matrix,i);
                    SolveCol(matrix,j);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==-1)
                matrix[i][j]=0;
            }
        }
        return ;
    }
};
