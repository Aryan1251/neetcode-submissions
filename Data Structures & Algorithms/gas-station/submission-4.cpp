class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficit=0;
        int balance=0;
        int n=gas.size();
        int st=0;
        for(int i=0;i<n;i++)
        {
            balance+=(gas[i]-cost[i]);
            if(balance<0)
            {
                deficit+=abs(balance);
                balance=0;
                st=i+1;
            }
        }
        if(balance-deficit>=0) return st;
        return -1;
    }
};
