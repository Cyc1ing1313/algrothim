#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:

    int firstMissingPositive(vector<int>& nums) {
        int guess = 1;
        int n  = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==guess){
                guess++;
            }
        }
        return guess;
    }

    int firstMissingPositiveV2(vector<int>& nums){
        unordered_set<int> set;
        int n = nums.size();
        int guess = 1;
        for(int i=0;i<n;i++){
            set.insert(nums[i]);
            while(set.count(guess)){
                guess++;
            }
        }
        return guess;
    }

    int firstMissingPositiveV3(vector<int>& nums){
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]!=i+1){
                if(nums[i]<=0 || nums[i] > n || nums[nums[i]-1]==nums[i])break;
                int temp = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = temp;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;
    }

};