class Solution {
    int Solve(vector<int>& cost,int index)
    {
        if(index>=cost.size()) return 0;

        int op1=cost[index]+Solve(cost,index+1);
        int op2=cost[index]+Solve(cost,index+2);

        return min(op1,op2);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int op1=Solve(cost,0);
        int op2=Solve(cost,1);

        return min(op1,op2);
    }
};
