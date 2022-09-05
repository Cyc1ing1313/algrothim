#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> need, has;
        for (auto &c : t)
        {
            need[c] += 1;
        }
        int i = 0, j = 0;
        string res;
        int cnt = 0;
        int m = s.length();
        int n = t.length();
        for (int i = 0, j = 0; i < m; i++)
        {
            has[s[i]]++;
            if (has[s[i]] <= need[s[i]])
                cnt++;
            while (has[s[j]] > need[s[j]])
            {
                has[s[j]]--;
                j++;
            }
            if (cnt == t.length())
            {
                if (res.empty() || res.length() > i - j + 1)
                {
                    res = s.substr(j, i - j + 1);
                }
            }
        }
        return res;
    }
};