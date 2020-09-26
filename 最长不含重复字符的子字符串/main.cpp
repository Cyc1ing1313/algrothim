#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int ret = 0;
        unordered_map<char,int> window;
        while(right<s.size()){
            char c1 = s[right];
            window[c1]++;
            right++;
            while(window[c1]>1){
                char c2 = s[left];
                window[c2]--;
                left++;
            }
            ret = max({ret,right-left});
        } 
        return ret;
    }
};