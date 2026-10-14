class Solution {
    int Solve(vector<int>& cost,int ind)
    {
        if(ind>=cost.size()) return 0;

        int op1=cost[ind]+Solve(cost,ind+1);
        int op2=cost[ind]+Solve(cost,ind+2);

        return min(op1,op2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int op1=Solve(cost,0);
        int op2=Solve(cost,1);
        return min(op1,op2);
    }
};
