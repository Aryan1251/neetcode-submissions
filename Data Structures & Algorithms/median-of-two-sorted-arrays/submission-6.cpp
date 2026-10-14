class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int len=(n1+n2);
        int cnt1=len/2;
        int cnt2=cnt1-1;
        int index=-1;
        int i=0,j=0,el1=-1,el2=-1;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<nums2[j])
            {
                i++;
                index++;
                if(index==cnt1) el1=nums1[i-1];
                else if(index==cnt2) el2=nums1[i-1]; 
            }else
            {
                j++;
                index++;
                if(index==cnt1) el1=nums2[j-1];
                else if(index==cnt2) el2=nums2[j-1];
            }
        }
        while(i<n1)
        {
            i++;
            index++;
            if(index==cnt1) el1=nums1[i-1];
            else if(index==cnt2) el2=nums1[i-1]; 
        }
        while(j<n2)
        {
            j++;
            index++;
            if(index==cnt1) el1=nums2[j-1];
            else if(index==cnt2) el2=nums2[j-1];
        }
        if(len%2==0)
        {
            return (el1+el2)/2.0;
        }
        return el1;
    }
};
