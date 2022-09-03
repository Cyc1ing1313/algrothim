#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        ser(root,s);
        return s;
    }

    string ser(TreeNode* root,string& s) {
        if(!root) s += "#,";
        else {
            s += to_string(root->val)+",";
            ser(root->left,s);
            ser(root->right,s);
        }
    }

    TreeNode* des(list<string> &arr) {
        if(arr.front()=="#") {
            arr.erase(arr.begin());
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(arr.front()));
        arr.pop_front();
        root->left = des(arr);
        root->right = des(arr);
        return root; 
    }


    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {   
        list<string> dataArr;
        string s;
        for(auto &c : data) {
            if(c==',') {
                dataArr.push_back(s);
                s.clear();
            }else {
                s.push_back(c);
            }
        }
        if(!s.empty()){
            dataArr.push_back(s);
        }
        return des(dataArr);
    }
};