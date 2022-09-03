
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        unordered_map<char,int> window;
        int count = 0;
        int ret=0;
        while(right<s.size()){
            char c1 = s[right];
            window[c1]++;
            if(window[c1]>1){
                count++;
            }
            right++;
            while(count>0){
                char c2 = s[left];
                window[c2]--;
                if(window[c2]==1){
                    count--;
                }
                left++;
            }
            if(ret<right-left){
                ret = right-left;
            }
        }
        return ret;
    }
};