#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i=0;count<n;i++){
            int prev = nums[i];
            int curr = i;
            do{
                int next = (curr+k)%n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                curr = next;
                count++;
            }while(curr!=i);
        }
    }

    void rotateV2(vector<int>& nums, int k){
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k%nums.size());
        reverse(nums.begin()+k%nums.size(),nums.end());
    }
};