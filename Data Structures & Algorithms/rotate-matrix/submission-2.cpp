class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        int i=0,j=m-1;
        while(i<j)
        {
            for(int row=0;row<n;row++)
            {
                swap(matrix[row][i],matrix[row][j]);
            }
            i++;
            j--;
        }
        return ;
    }
};
