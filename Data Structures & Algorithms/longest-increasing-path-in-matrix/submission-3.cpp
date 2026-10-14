class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>>> >pq;

        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int> >dist(n,vector<int>(m,1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            pq.push({matrix[i][j],{i,j}});
        }

        while(!pq.empty())
        {
            int val=pq.top().first;
            int rowInd=pq.top().second.first;
            int colInd=pq.top().second.second;

            pq.pop();

            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};

            for(int i=0;i<4;i++)
            {
                int rInd=row[i]+rowInd;
                int cInd=col[i]+colInd;
                if(rInd>=0 && cInd>=0 && rInd<n && cInd<m && matrix[rInd][cInd]>matrix[rowInd][colInd] && dist[rowInd][colInd]+1>dist[rInd][cInd])
                dist[rInd][cInd]=dist[rowInd][colInd]+1;
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                maxi=max(maxi,dist[i][j]);
            }
        }
        return maxi;
    }
};
