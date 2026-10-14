class Solution {
    int Solve(vector<int>& coins,int amount,int ind)
    {
        if(amount==0) return 0;
        if(ind>=coins.size()) return INT_MAX;

        int op1=INT_MAX;
        if(coins[ind]<=amount)
        {
            op1=Solve(coins,amount-coins[ind],ind);
            if(op1!=INT_MAX)
            op1+=1;
        }

        int op2=Solve(coins,amount,ind+1);

        return min(op1,op2);
    }
public:
    int coinChange(vector<int>& coins, int amount) {

        int ans= Solve(coins,amount,0);
        return ans==INT_MAX?-1:ans;
    }
};
