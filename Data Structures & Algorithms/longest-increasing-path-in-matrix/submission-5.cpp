class Solution {
    bool isValid(int i,int j,int prev_i,int prev_j,vector<vector<int> >& mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        if(i<n && i>=0 && j<m && j>=0 && mat[i][j]>mat[prev_i][prev_j]) return 1;
        return 0;
    }
    int Solve(vector<vector<int> >& mat,vector<vector<int> >& dp,int i,int j)
    {
        int n=mat.size();
        int m=mat[0].size();
        if(i>=n || i<0 || j>=m || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};

        int ans=0;
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(rInd,cInd,i,j,mat))
            {
                ans=max(ans,1+Solve(mat,dp,rInd,cInd));
            }
        }
        return dp[i][j]= ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=0;
        vector<vector<int> >dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxi=max(maxi,Solve(matrix,dp,i,j));
                dp.assign(n, vector<int>(m, -1));
            }
        }
        return maxi+1;
    }
};
