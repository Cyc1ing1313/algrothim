
// 给你一个整数 n，请返回长度为 n 、仅由元音 (a, e, i, o, u) 组成且按 字典序排列 的字符串数量。

// 字符串 s 按 字典序排列 需要满足：对于所有有效的 i，s[i] 在字母表中的位置总是与 s[i+1] 相同或在 s[i+1] 之前。

 

// 示例 1：

// 输入：n = 1
// 输出：5
// 解释：仅由元音组成的 5 个字典序字符串为 ["a","e","i","o","u"]
// 示例 2：

// 输入：n = 2
// 输出：15
// 解释：仅由元音组成的 15 个字典序字符串为
// ["aa","ae","ai","ao","au","ee","ei","eo","eu","ii","io","iu","oo","ou","uu"]
// 注意，"ea" 不是符合题意的字符串，因为 'e' 在字母表中的位置比 'a' 靠后
// 示例 3：

// 输入：n = 33
// 输出：66045

#include<string>
using namespace std;
class Solution {
public:
    int ret=0;
    char alpha[5]= {'a','e','i','o','u'};
    int countVowelStrings(int n) {
        helper(n,0,'z');
        return ret;
    }

    void helper(int n,int index,char tail){
        if(index==n) {
            ret=ret+1;
            return;
        }
        for(int i=0;i<5;i++){
            if(index==0||alpha[i]<=tail){
                helper(n,index+1,alpha[i]);
            }
        }
    }
};