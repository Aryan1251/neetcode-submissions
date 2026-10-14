class Solution {
    bool isValid(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j] && !vis[i][j]) return 1;
        return 0;
    }
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int area=0;
        while(!q.empty())
        {
            int rInd=q.front().first;
            int cInd=q.front().second;
            q.pop();

            area++;
            int row[]={0,1,0,-1};
            int col[]={-1,0,1,0};

            for(int i=0;i<4;i++)
            {
                int rowInd=row[i]+rInd;
                int colInd=col[i]+cInd;
                if(isValid(rowInd,colInd,grid,vis))
                {
                    q.push({rowInd,colInd});
                    vis[rowInd][colInd]=1;
                }
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(),area=0;
        vector<vector<int> >vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    int ans=bfs(grid,vis,i,j);
                    area=max(area,ans);
                }
            }
        }
        return area;
    }
};
