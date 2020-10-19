/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
#include<vector>
using namespace std;
class Bucket{
    public:
        bool used = false;
        int maxval = INT_MAX; 
        int minval = INT_MIN;
};
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.empty() || nums.size() < 2)
            return 0;

        int mini = *min_element(nums.begin(), nums.end()),
            maxi = *max_element(nums.begin(), nums.end());

        int bucketSize = max(1, (maxi - mini) / ((int)nums.size() - 1));        // bucket size or capacity
        int bucketNum = (maxi - mini) / bucketSize + 1;                         // number of buckets
        vector<Bucket> buckets(bucketNum);

        for (auto&& num : nums) {
            int bucketIdx = (num - mini) / bucketSize;                          // locating correct bucket
            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
            buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
        }

        int prevBucketMax = mini, maxGap = 0;
        for (auto&& bucket : buckets) {
            if (!bucket.used)
                continue;

            maxGap = max(maxGap, bucket.minval - prevBucketMax);
            prevBucketMax = bucket.maxval;
        }

        return maxGap;
    }
};
// @lc code=end

