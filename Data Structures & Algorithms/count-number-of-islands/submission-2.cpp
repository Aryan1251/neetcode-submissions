class Solution {
    bool isValid(int i,int j,vector<vector<int> >& vis,vector<vector<char> >& grid)
    {
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && grid[i][j]=='1' && !vis[i][j])
        return 1;
        else
        return 0;
    }
    void dfs(vector<vector<char> >& grid,vector<vector<int> >& vis,int i,int j)
    {
        vis[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(rInd,cInd,vis,grid))
            {
                dfs(grid,vis,rInd,cInd);
            }
        }
        return ;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int> >vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    dfs(grid,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
