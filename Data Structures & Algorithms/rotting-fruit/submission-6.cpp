class Solution {
    bool isValid(int i,int j,vector<vector<int> >& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1) return 1;
        return 0;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int> >q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                q.push({{i,j},0});
            }
        }
        int time=0;
        while(!q.empty())
        {
            auto rInd=q.front().first.first;
            auto cInd=q.front().first.second;
            auto cnt=q.front().second;
            time=cnt;
            q.pop();

            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};
            for(int k=0;k<4;k++)
            {
                int rowInd=row[k]+rInd;
                int colInd=col[k]+cInd;
                if(isValid(rowInd,colInd,grid))
                {
                    grid[rowInd][colInd]=2;
                    q.push({{rowInd,colInd},cnt+1});
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
        return time;
    }
};
