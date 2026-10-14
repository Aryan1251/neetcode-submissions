class Solution {
    private:
    bool chkValid(vector<vector<int> >& grid,vector<vector<int> >& vis,int i,int j)
    {
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && !vis[i][j] && grid[i][j])
        return true;
        return false;
    }
    void dfs(vector<vector<int> >& grid,vector<vector<int> >& vis,int i,int j,int &cnt)
    {
        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(chkValid(grid,vis,rInd,cInd))
            {
                cnt++;
                dfs(grid,vis,rInd,cInd,cnt);
            }
        }
        return ;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j])
                {
                    int cnt=1;
                    dfs(grid,vis,i,j,cnt);
                    maxi=max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};
