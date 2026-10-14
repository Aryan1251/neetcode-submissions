class Solution {
    bool isValid(int i,int j,vector<vector<int> >& grid,vector<vector<int> >& vis)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j] && !vis[i][j]) return 1;
        return 0;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>> >q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=1;
                    q.push({i,{j,0}});
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int rInd=q.front().first;
            int cInd=q.front().second.first;
            int T=q.front().second.second;
            q.pop();

            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};

            for(int i=0;i<4;i++)
            {
                int rowInd=row[i]+rInd;
                int colInd=col[i]+cInd;

                if(isValid(rowInd,colInd,grid,vis))
                {
                    vis[rowInd][colInd]=1;
                    q.push({rowInd,{colInd,T+1}});
                }
            }
            ans=T;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j]) return -1;
            }
        }
        return ans;
    }
};
