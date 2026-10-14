class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return ;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j>=i) swap(matrix[i][j],matrix[j][i]);
            }
        }
        int i=0,j=n-1;
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
