class Solution {
    bool isValid(int i,int j,int old_i,int old_j,vector<vector<int> >& vis,vector<vector<int> >& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m && !vis[i][j] && grid[i][j]>=grid[old_i][old_j])
        return true;
        return false;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int> >vis1(n,vector<int>(m,0));
        vector<vector<int> >vis2(n,vector<int>(m,0));
        queue<pair<int,int> >q;

        for(int j=0;j<m;j++)
        {
            vis1[0][j]=1;
            q.push({0,j});
        }

        for(int i=0;i<n;i++)
        {
            vis1[i][0]=1;
            q.push({i,0});
        }

        while(!q.empty())
        {
            int rInd=q.front().first;
            int cInd=q.front().second;
            q.pop();

            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};

            for(int i=0;i<4;i++)
            {
                int rrInd=row[i]+rInd;
                int ccInd=col[i]+cInd;
                if(isValid(rrInd,ccInd,rInd,cInd,vis1,heights))
                {
                    q.push({rrInd,ccInd});
                    vis1[rrInd][ccInd]=1;
                }
            }
        }

        for(int j=0;j<m;j++)
        {
            vis2[n-1][j]=1;
            q.push({n-1,j});
        }

        for(int i=0;i<n;i++)
        {
            vis2[i][m-1]=1;
            q.push({i,m-1});
        }

        while(!q.empty())
        {
            int rInd=q.front().first;
            int cInd=q.front().second;
            q.pop();

            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};

            for(int i=0;i<4;i++)
            {
                int rrInd=row[i]+rInd;
                int ccInd=col[i]+cInd;
                if(isValid(rrInd,ccInd,rInd,cInd,vis2,heights))
                {
                    q.push({rrInd,ccInd});
                    vis2[rrInd][ccInd]=1;
                }
            }
        }

        vector<vector<int> >ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis1[i][j]==1 && vis2[i][j]==1)
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};
