class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(n1==0)
        {
            if(n2%2==0)
            {
                return (nums2[n2/2-1]+nums2[n2/2])/2.0;
            }
            return (double)nums2[n2/2];
        }
        if(n2==0)
        {
            if(n1%2==0)
            {
                return (nums1[n1/2-1]+nums1[n1/2])/2.0;
            }
            return (double)nums1[n1/2];
        }
        int len=(n1+n2);
        int val=len/2;
        int index=-1;
        int i=0,j=0;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j])
            {
                i++;
                index++;
                if(index==val)
                {
                    if(len%2==1) return (double)nums1[i-1];
                    else 
                    {
                        double ans=(nums1[i-1]+nums2[j-1])/2.0;
                        return ans;
                    }
                }
            }else
            {
                j++;
                index++;
                if(index==val)
                {
                    if(len%2==1) return (double)nums2[j-1];
                    else 
                    {
                        double ans=(nums1[i-1]+nums2[j-1])/2.0;
                        return ans;
                    }
                }
            }
        }
        while(i<n1)
        {
            i++;
            index++;
            if(index==val)
            {
                if(len%2==1) return (double)nums1[i-1];
                else 
                {
                    double ans=(nums1[i-1]+nums2[j-1])/2.0;
                    return ans;
                }
            }
        }
        while(j<n2)
        {
            j++;
            index++;
            if(index==val)
            {
                if(len%2==1) return (double)nums2[j-1];
                else 
                {
                    double ans=(nums1[i-1]+nums2[j-1])/2.0;
                    return ans;
                }
            }
        }
    }
};
