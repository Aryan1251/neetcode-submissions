class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int firstRow=0,firstCol=0,lastRow=n-1,lastCol=m-1;
        vector<int>v;
        while(firstRow<=lastRow && firstCol<=lastCol)
        {
            // 1st row
            for(int j=firstCol;j<=lastCol && firstRow<=lastRow;j++)
            {
                v.push_back(matrix[firstRow][j]);
            }
            firstRow++;
            //last col
            for(int i=firstRow;i<=lastRow && firstCol<=lastCol;i++)
            {
                v.push_back(matrix[i][lastCol]);
            }
            lastCol--;
            //last row
            for(int j=lastCol;j>=firstCol && firstRow<=lastRow;j--)
            {
                v.push_back(matrix[lastRow][j]);
            }
            lastRow--;
            //first col
            for(int i=lastRow;i>=firstRow && firstCol<=lastCol;i--)
            {
                v.push_back(matrix[i][firstCol]);
            }
            firstCol++;
        }
        return v;
    }
};
