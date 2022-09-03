#include<array>
using namespace std;
int binary_search(int arr[],int target){
    int left=0;
    int right = sizeof(arr)/sizeof(arr[0])-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(arr[mid]==target){
            return mid;
        }else if(arr[mid]<target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return -1;
}

int left_bound(int nums[],int target){
    int left=0;
    int n = sizeof(nums)/sizeof(nums[0]);
    int right= n;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(nums[mid]=target){
            right = mid-1;
        }else if(nums[mid]<target){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    if(left>=n||nums[n]!=target){
        return -1;
    }
    return left;
}

int right_bound(int nums[],int target){
    int left=0;
    int n = sizeof(nums)/sizeof(nums[0]);
    int right= n;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(nums[mid]=target){
            left = mid+1;
        }else if(nums[mid]<target){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    if(right<0 || nums[right]!=target){
        return -1;
    }
    return right;
}