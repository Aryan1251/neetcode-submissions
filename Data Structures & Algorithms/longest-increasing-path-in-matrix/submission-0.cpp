class Solution {
    private:
    bool isValid(int previ,int prevj,int i,int j,int n,int m,vector<vector<int> >& matrix)
    {
        if(i>=0 && j>=0 && i<n && j<m && matrix[previ][prevj]<matrix[i][j])
        return true;
        return false;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        priority_queue<pair<int,pair<int,int>> >pq;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pq.push({1,{i,j}});
            }
        }
        int maxi=1;
        while(!pq.empty())
        {
            auto cnt=pq.top().first;
            auto rInd=pq.top().second.first;
            auto cInd=pq.top().second.second;
            pq.pop();
            maxi=max(maxi,cnt);
            int row[]={0,-1,0,1};
            int col[]={-1,0,1,0};
            for(int i=0;i<4;i++)
            {
                int rowIndex=row[i]+rInd;
                int colIndex=col[i]+cInd;
                if(isValid(rInd,cInd,rowIndex,colIndex,n,m,matrix))
                {
                    pq.push({cnt+1,{rowIndex,colIndex}});
                }
            }
        }
        return maxi;
    }
};
