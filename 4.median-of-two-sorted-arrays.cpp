/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
       return (findKth((len1+len2+1)/2,nums1,nums2,0,0)+findKth((len1+len2+2)/2,nums1,nums2,0,0))*0.5; 
    }

    int findKth(int k,vector<int>& nums1, vector<int>& nums2,int l1,int l2) {
        int end1= nums1.size()-1;
        int end2 = nums2.size()-1;
        int len1 = end1-l1+1;
        int len2 = end2-l2+1;
        if (len2<len1){
            return findKth(k,nums2,nums1,l2,l1);
        }
        if (len1==0){
            return nums2[l2+k-1];
        }
        if (k==1){
            return min(nums1[l1],nums2[l2]);
        }
        int s1 = l1+ min(len1,k/2)-1;
         int s2 = l2 + min(len2,k/2)-1;
        if(nums1[s1]<nums2[s2]){
            return findKth(k-(s1-l1+1),nums1,nums2,s1+1,l2);
        }else{
            return findKth(k-(s2-l2+1),nums1,nums2,l1,s2+1);
        }
    }

    int min(int a,int b){
        if(a<b) return a;
        return b;
    }
};
// @lc code=end

