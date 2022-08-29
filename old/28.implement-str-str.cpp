/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
#include<string>
using namespace std;
class Solution {
public:
    int next[1000000];
    int strStr(string haystack, string needle) {
        if(haystack == needle || needle == "") return 0;
        int n = haystack.size();
        int m = needle.size();
        haystack = '0'+haystack;
        needle = '0'+needle;
        next[1]=0;
        for(int i=2,j=0;i<=m;i++){
            while(j&&needle[i]!=needle[j+1]) j = next[j];
            if(needle[i]==needle[j+1]) j++;
            next[i] = j;
        }
        for(int i=1,j=0;i<=n;i++){
            while(j&&haystack[i]!= needle[j+1]) j = next[j];
            if(haystack[i] == needle[j+1]) j++;
            if(j==m){
                return i-m;
            }
        }
        return -1;
    }
    // int strStr(string haystack, string needle) {
    //     int i = 0;
    //     int j = 0;
    //     while(haystack[i]!='\0'&&needle[j]!='\0')
    //     {
    //         if(needle[j]==haystack[i])//判断是否相等
    //         {
    //             j++;
    //             i++;
    //         }
    //         else//不相等退回开始的位置，i+1，j=0;
    //         {
    //             i = i - j + 1;
    //             j = 0;
    //         }

    //     }
    //     if(j == needle.length())//j为步长
    //     return  i-j;
    //     return -1;
    // }
};
// @lc code=end

