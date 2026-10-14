class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        int n=hand.size();
        sort(hand.begin(),hand.end());
        for(int i=0;i<n;i++)
        {
            if(hand[i]==-1) continue;
            int element=hand[i]+1;
            hand[i]=-1;
            int k=groupSize-1;
            while(k--)
            {
                int ind=find(hand.begin(),hand.end(),element)-hand.begin();
                if(ind>=0 && ind<n)
                {
                    element+=1;
                    hand[ind]=-1;
                }
                else return false;
            }
        }
        return true;
    }
};
