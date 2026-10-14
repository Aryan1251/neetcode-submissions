class Solution {
public:
    bool chkValid(int i,int j,vector<vector<int> >& grid,vector<vector<int> >& vis)
    {
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && !vis[i][j] &&  grid[i][j])
        return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,pair<int,int>> >q;
        vector<vector<int> >vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int t=0;
        while(!q.empty())
        {
            t=q.front().first;
            auto rowInd=q.front().second.first;
            auto colInd=q.front().second.second;
            q.pop();

            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};
            for(int i=0;i<4;i++)
            {
                int rInd=row[i]+rowInd;
                int cInd=col[i]+colInd;
                if(chkValid(rInd,cInd,grid,vis))
                {
                    q.push({t+1,{rInd,cInd}});
                    vis[rInd][cInd]=1;
                }
            }
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(!vis[i][j] && grid[i][j]) return -1;
            }
        }
        return t;
    }
};
