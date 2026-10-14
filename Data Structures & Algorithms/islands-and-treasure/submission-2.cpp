class Solution {
    int INF = 2147483647;
    bool isValid(int i,int j,vector<vector<int> >& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==INF)
        return 1;
        return 0;
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >dis(n+1,vector<int>(m+1,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                pq.push({0,{i,j}});
            }
        }

        while(!pq.empty())
        {
            auto cnt=pq.top().first;
            auto rowInd=pq.top().second.first;
            auto colInd=pq.top().second.second;
            pq.pop();

            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};

            for(int k=0;k<4;k++)
            {
                int rInd=row[k]+rowInd;
                int cInd=col[k]+colInd;
                if(isValid(rInd,cInd,grid))
                {
                    if(cnt+1<dis[rInd][cInd])
                    {
                        dis[rInd][cInd]=cnt+1;
                        pq.push({dis[rInd][cInd],{rInd,cInd}});
                    }
                }

            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==INF)
                grid[i][j]=dis[i][j];
            }
        }
        return ;
    }
};
