class Solution {
    private:
    int Solve(vector<int>& coins,int amount,int index)
    {
        if(index>=coins.size())
        {
            if(amount==0) return 0;
            return INT_MAX;
        }
        if(amount==0) return 0;

        int op1=INT_MAX;
        if(coins[index]<=amount)
        {
            op1=Solve(coins,amount-coins[index],index);
            if(op1!=INT_MAX)
            op1+=1;
        }
        int op2=Solve(coins,amount,index+1);

        return min(op1,op2);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int ans=Solve(coins,amount,0);
        return ans==INT_MAX?-1:ans;
    }
};
