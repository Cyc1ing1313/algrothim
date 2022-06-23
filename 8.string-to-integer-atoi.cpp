/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
#include<bits/stdc++/h>
using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size(),i=0;
        int ret=0,base=1,neg=1;
        while(s[i]==' '){i++;}
        if(s[i]=='-') {neg = -1;i++;}
        // while(s[i]==' '){i++;}
        s = s.substr(i,n-i);
        n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]>'9' || s[i]<'0') continue;
            ret += base*(s[i]-'0');
            base = base* 10;
        }
        return ret*neg;
    }
};
// @lc code=end

