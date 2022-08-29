/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    unordered_set<string> set;
    // int son[100000][26],cnt[100000],idx;
    // void insert(string s){
    //     int p =0;
    //     for(int i=0;i<s.size();i++){
    //         int u = s[i]-'a';
    //         if(!son[p][u]) son[p][u] = ++idx;
    //         p = son[p][u];
    //     }
    //     cnt[p]++;
    // }

    // int find(string s){
    //     int p=0;
    //     for(int i=0;i<s.size();i++){
    //         int u = s[i]-'a';
    //         if(!son[p][u]) return 0;
    //         p = son[p][u];
    //     }
    //     return cnt[p];
    // }
    bool dfs(string s,int start,int count){
        if(start>=s.size()&&count>=2) return true;
        for(int i=start;i<s.size();i++){
            // if(find(s.substr(start,i-start+1))){
            //     if(dfs(s,i+1,count+1)){
            //         return true;
            //     }
            // }
            if(set.count(s.substr(start,i-start+1))){
                if(dfs(s,i+1,count+1)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> ret;
        for(auto word:words){
            // insert(word);
            set.insert(word);
        }
        for(auto word:words){
            if(dfs(word,0,0)){
                ret.push_back(word);
            }
        }
        return ret;
    }
};
// @lc code=end

