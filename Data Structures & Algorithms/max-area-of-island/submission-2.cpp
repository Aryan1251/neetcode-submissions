class Solution {
    bool isValid(vector<vector<int> >& vis,vector<vector<int> >& grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && i<n && j>=0 && j<m && !vis[i][j] && grid[i][j]==1) return 1;
        return 0;
    }
    int dfs(vector<vector<int> >& vis,int i,int j,vector<vector<int> >& grid,int& ans)
    {
        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        ans++;
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(vis,grid,rInd,cInd))
            {
                dfs(vis,rInd,cInd,grid,ans);
            }
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));
        int ans=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cnt=0;
                if(!vis[i][j] && grid[i][j]==1)
                ans=max(ans,dfs(vis,i,j,grid,cnt));
            }
        }
        return ans;
    }
};
