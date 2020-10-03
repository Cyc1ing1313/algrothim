#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left=0;
        int right=0;
        unordered_map<char,int> window;
        unordered_map<char,int> needs;
        vector<int> ret;
        int match = 0;
        while(right<s.size()){
            char c1 = s[right];
            if(needs.count(c1)){
                window[c1]++;
                if(window[c1]==needs[c1]){
                    match++;
                }
            }
            right++;
            while(match == needs.size()){
                if(right-left == p.size()){
                    ret.push_back(left);
                }
                char c2 = s[left];
                if(needs.count(c2)){
                    window[c2]--;
                    if(window[c2]<needs[c2]){
                        match--;
                    }
                }
                left++;
            }
        
        }
        return ret;


    }
};