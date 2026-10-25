class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int cnt1=(n+m)/2,cnt2=((n+m)/2)+1,el1=-1,el2=-1;

        int i=0,j=0;

        while(i<n && j<m)
        {
            if(nums1[i]<nums2[j])
            {
                cnt1--;
                cnt2--;
                if(cnt1==0) el1=nums1[i];
                else if(cnt2==0) el2=nums1[i];
                i++;
            }else
            {
                cnt1--;
                cnt2--;
                if(cnt1==0) el1=nums2[j];
                else if(cnt2==0) el2=nums2[j];
                j++;
            }
        }

        while(i<n)
        {
            cnt1--;
            cnt2--;
            if(cnt1==0) el1=nums1[i];
            else if(cnt2==0) el2=nums1[i];
            i++;
        }
        while(j<m)
        {
            cnt1--;
            cnt2--;
            if(cnt1==0) el1=nums2[j];
            else if(cnt2==0) el2=nums2[j];
            j++;
        }
        if((n+m)%2==0) return ((el1+el2)/2.0);
        else return el2;
    }
};
