class Solution {
    int Solve(vector<int>& prices,int buy,int ind)
    {
        if(ind>=prices.size()) return 0;

        if(buy)
        {
            int op1=-prices[ind]+Solve(prices,!buy,ind+1);
            int op2=Solve(prices,buy,ind+1);
            return max(op1,op2);
        }else
        {
            int op1=prices[ind]+Solve(prices,!buy,ind+2);
            int op2=Solve(prices,buy,ind+1);
            return max(op1,op2);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int ans=Solve(prices,1,0);
        return ans;
    }
};
