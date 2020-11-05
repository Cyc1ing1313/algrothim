#include<vector>
using namespace std;
class Solution {
public:

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n,0);
        return mergeSort(nums,t,0,n-1);
    }

    int mergeSort(vector<int>& nums,vector<int>& t,int l,int r){
        if(r<=l) return 0;
        int mid = (l+r)/2;
        int ret= mergeSort(nums,t,l,mid)+mergeSort(nums,t,mid+1,r);
        int i=l;int j=mid+1;
        int ti = l;
        while(i<=mid&&j<=r){
            if(nums[i]<nums[j]){
                ret+= j-mid-1;
                t[ti] = nums[i++];
            }else{
                t[ti]=nums[j++];
            }
            ti++;
        }
        while(i<=mid){
            ret += j-mid-1;
            t[ti++] = nums[i++];
        }
        while(j<=r){
            t[ti++] = nums[j++];
        }
        copy(t.begin() + l, t.begin() + r + 1, nums.begin() + l);
        return ret;

    }
};