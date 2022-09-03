#include<vector>
#include<stack>
#include<iostream>
using namespace std;

vector<int> nextGreaterElem(vector<int>& nums){
    vector<int> ret(nums.size());
    stack<int> s;
    for(int i=nums.size()-1;i>=0;i--){
        while(!s.empty()&&s.top()<=nums[i]){
            s.pop();
        }
        ret[i] = s.empty()?-1:s.top();
        s.push(nums[i]);
    }
    return ret;
}

vector<int> nextGreaterElemWithLoop(vector<int>& ring){
    int n = ring.size();
    vector<int> ret(n);
    stack<int> s;
    for(int i=2*n-1;i>=0;i--){
        while(!s.empty()&&ring[i%n]>s.top()){
            s.pop();
        }
        ret[i%n] = s.empty()?-1:ring[i%n];
        s.push(ret[i%n]);
    }
    return ret;
}

int main(){
    vector<int> arr = {1,2,3,4};
    vector<int> ret = nextGreaterElem(arr);
    for(auto i:ret){
        cout<<i<<endl;
    }
}