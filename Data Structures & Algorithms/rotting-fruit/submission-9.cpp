class Solution {
    bool isValid(int i,int j,vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1)
        return 1;
        return 0;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,pair<int,int>> >q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                q.push({0,{i,j}});
            }
        }
        int ans=0;
        while(!q.empty())
        {
            int T=q.front().first;
            int rInd=q.front().second.first;
            int cInd=q.front().second.second;
            q.pop();
            ans=T;

            int row[]={0,1,0,-1};
            int col[]={-1,0,1,0};

            for(int i=0;i<4;i++)
            {
                int rowInd=row[i]+rInd;
                int colInd=col[i]+cInd;
                if(isValid(rowInd,colInd,grid))
                {
                    grid[rowInd][colInd]=2;
                    q.push({T+1,{rowInd,colInd}});
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
};
