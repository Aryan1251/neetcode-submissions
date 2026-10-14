class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int stRow=0,stCol=0,endRow=row-1,endCol=col-1;
        vector<int>ans;
        int cnt=row*col;
        while(stRow<=endRow && stCol<=endCol)
        {
            //1st row
            for(int j=stCol;j<=endCol && stRow<=endRow;j++)
            {
                ans.push_back(matrix[stRow][j]);
            }
            stRow++;

            //last Col
            for(int i=stRow;i<=endRow && stCol<=endCol;i++)
            {
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;

            //lastRow
            for(int j=endCol;j>=stCol && stRow<=endRow;j--)
            {
                ans.push_back(matrix[endRow][j]);
            }
            endRow--;

            //1st Col
            for(int i=endRow;i>=stRow && stCol<=endCol;i--)
            {
                ans.push_back(matrix[i][stCol]);
            }
            stCol++;
        }
        return ans;
    }
};
