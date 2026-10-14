class MedianFinder {
public:
    priority_queue<double,vector<double>,greater<double> >mini;
    priority_queue<double>maxi;
    double median;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mini.empty() && maxi.empty())
        {
            mini.push(num);
            median=mini.top();
            return ;
        }
        else if(mini.size()==maxi.size()+1)
        {
            if(num<=median)
            {
                maxi.push(num);
            }else
            {
                double minTop=mini.top();
                mini.pop();
                maxi.push(minTop);
                mini.push(num);
            }
            median=(mini.top()+maxi.top())/2.0;
            return ;
        }
        else if(maxi.size()==mini.size()+1)
        {
            if(num>=median)
            {
                mini.push(num);
            }else
            {
                double maxiTop=maxi.top();
                maxi.pop();
                mini.push(maxiTop);
                maxi.push(num);
            }
            median=(mini.top()+maxi.top())/2.0;
            return ;
        }
        else if(mini.size()==maxi.size())
        {
            if(num>=median)
            {
                mini.push(num);
            }else
            {
                double maxiTop=maxi.top();
                maxi.pop();
                mini.push(maxiTop);
                maxi.push(num);
            }
            median =mini.top();
            return ;
        }
    }
    
    double findMedian() {
        return median;
    }
};
