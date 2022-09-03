// 给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。

// 如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。

//  

// 示例 1：

// 输入：nums = [1,1,4,2,3], x = 5
// 输出：2
// 解释：最佳解决方案是移除后两个元素，将 x 减到 0 。
// 示例 2：

// 输入：nums = [5,6,7,8,9], x = 4
// 输出：-1
// 示例 3：

// 输入：nums = [3,2,20,1,1,3], x = 10
// 输出：5
// 解释：最佳解决方案是移除后三个元素和前两个元素（总共 5 次操作），将 x 减到 0 。




#include<vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum=0;
        for(auto num:nums){
            sum += num;
        }
        int tar = sum-x;
        int l=0,r=0;
        int csum=0;
        int ret=-1;
        while(r<n){
            csum += nums[r++];
            while(csum > tar){
                csum -= nums[l++];
            }
            if(csum==tar){
                ret = max(ret,r-l);
            }
        }
        return ret==-1?-1:n-ret;
    }
};