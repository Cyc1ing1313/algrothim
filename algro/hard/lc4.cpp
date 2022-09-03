#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()+nums2.size();
        if(n%2==0) {
            int left = findK(nums1,0,nums2,0,n/2);
            int right = findK(nums1,0,nums2,0,n/2+1);
            return (left+right)/2.0;
        }else{
            return findK(nums1,0,nums2,0,n/2+1);
        }
    }

   int findK(vector<int>& nums1,int i,vector<int>& nums2,int j,int  k) {
        if(nums1.size()-i>nums2.size()-j) {
            return findK(nums2,j,nums1,i,k);
        }
        if(i==nums1.size()) {
            return nums2[j-1+k];
        }
        if(k==1) return min(nums1[i],nums2[j]);
        int ni = min(i+k/2,(int)nums1.size());
        int nj = min(j + k - k/2,(int)nums2.size());
        if(nums1[ni-1] < nums2[nj-1]) {
            return findK(nums1,ni,nums2,j,k-(ni-i));
        }else {
            return findK(nums1,i,nums2,nj,k-(nj-j));
        }
    }
};
