class Solution {
    bool chkValid(int i,int j,int currI,int currJ,vector<vector<int> >& vis,vector<vector<int> >& heights)
    {
        int n=heights.size();
        int m=heights[0].size();
        if(currI>=0 && currJ>=0 && currI<n && currJ<m && !vis[currI][currJ] && heights[currI][currJ]>=heights[i][j])
        return true;
        return false;
    }
    void dfs(vector<vector<int> >& vis,int i,int j,vector<vector<int> >& heights)
    {
        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(chkValid(i,j,rInd,cInd,vis,heights))
            dfs(vis,rInd,cInd,heights);
        }
        return ;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int> >pac(n,vector<int>(m,0));
        vector<vector<int> >atlantic(n,vector<int>(m,0));

        //pacific
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || j==0)
                {
                    dfs(pac,i,j,heights);
                }
            }
        }
        //atlantic
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==n-1 || j==m-1)
                {
                    dfs(atlantic,i,j,heights);
                }
            }
        }
        vector<vector<int> >ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j] && atlantic[i][j])
                ans.push_back({i,j});
            }
        }
        return ans;
        
    }
};
