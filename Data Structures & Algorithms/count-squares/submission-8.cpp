class CountSquares {
public:
    map<vector<int>,int>mp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        mp[point]++;
    }
    
    int count(vector<int> point) {
        if(mp.empty()) return 0;
        int xo=point[0];
        int yo=point[1];
        int cnt=0;
        for(auto vec: mp)
        {
            auto it=vec.first;
            int x=it[0];
            int y=it[1];

            if(abs(x-xo)!=abs(y-yo) || xo==x || y==yo) continue;
            int ans=mp[{x,y}]*mp[{xo,y}]*mp[{x,yo}];
            cnt+=ans;
        }
        return cnt;
    }
};
