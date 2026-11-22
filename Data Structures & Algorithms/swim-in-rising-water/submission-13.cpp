class Solution {
    bool isValid(int i,int j,vector<vector<int>>& grid,vector<vector<int> >& vis,int time)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]<=time && !vis[i][j]) return 1;
        return 0;
    }
    bool bfs(vector<vector<int>>& grid,int time)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int> >q;
        q.push({0,0});
        if(grid[0][0]>time) return false;
        vector<vector<int> >vis(n,vector<int>(m,0));
        vis[0][0]=1;
        while(!q.empty())
        {
            int rowIndex=q.front().first;
            int colIndex=q.front().second;
            if(rowIndex==n-1 && colIndex==m-1) return 1;

            q.pop();
            int row[]={-1,0,1,0};
            int col[]={0,-1,0,1};

            for(int i=0;i<4;i++)
            {
                int rInd=row[i]+rowIndex;
                int cInd=col[i]+colIndex;
                if(isValid(rInd,cInd,grid,vis,time))
                {
                    vis[rInd][cInd]=1;
                    q.push({rInd,cInd});
                }
            }
        }
        return false;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int maxTime=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxTime=max(maxTime,grid[i][j]);
            }
        }

        int s=0,e=maxTime,ans=-1;
        while(s<=e)
        {
            int mid=(s+e)>>1;

            if(bfs(grid,mid))
            {
                ans=mid;
                e=mid-1;
            }else
            s++;
        }
        return ans;
    }
};
