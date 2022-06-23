/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int len = 0,st = 0;
        for(int i=0;i<n;i++){
            helper(s,i,i,&len,&st);
            if(i+1<n) helper(s,i,i+1,&len,&st);
        }
        return s.substr(st,len);
    }

    int max(int a,int b){
        if (a<b) return b;
        return a;
    }

    void helper(string s,int a,int b,int *len,int *st){
        int i = a,j=b;
        for(;i>=0&&j<s.length();i--,j++){
            if(s[i]!=s[j]) break;
            if((j-i+1)>*len){
                *len = j-i+1;
                *st = i;
            }
        }
        return;
    }
};
// @lc code=end

