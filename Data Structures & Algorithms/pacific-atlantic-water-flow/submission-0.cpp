class Solution {
    private:
    bool isValid(int previ,int prevj,int i,int j,vector<vector<int>>& heights,vector<vector<int>>& pacific)
    {
        int n=heights.size();
        int m=heights[0].size();
        if(i>=0 && j>=0 && i<n && j<m && !pacific[i][j] && heights[previ][prevj]<=heights[i][j])
        return true;
        return false;
    }
    void Solve(vector<vector<int>>& heights,vector<vector<int>>& pacific,int i,int j)
    {
        pacific[i][j]=1;
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int k=0;k<4;k++)
        {
            int rInd=row[k]+i;
            int cInd=col[k]+j;
            if(isValid(i,j,rInd,cInd,heights,pacific))
            {
                Solve(heights,pacific,rInd,cInd);
            }
        }
        return ;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int> >pacific(n,vector<int>(m,0));
        vector<vector<int> >atlantic(n,vector<int>(m,0));

        for(int j=0;j<m;j++)
        {
            Solve(heights,pacific,0,j);
        }
        for(int i=0;i<n;i++)
        {
            Solve(heights,pacific,i,0);
        }
        for(int i=0;i<n;i++)
        {
            Solve(heights,atlantic,i,m-1);
        }
        for(int j=0;j<m;j++)
        {
            Solve(heights,atlantic,n-1,j);
        }
        vector<vector<int> >ans; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                ans.push_back({i,j});
            }
        }
        return ans;
    }
};
