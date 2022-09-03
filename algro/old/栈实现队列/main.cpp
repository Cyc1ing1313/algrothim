#include<stack>
#include<iostream>
using namespace std;
class MyQueue{
    private:
        stack<int> s1;
        stack<int> s2;
        int head = 0;
    public:
        void push(int x){
            s1.push(x);
        }

        int pop(){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());s1.pop();
                }
            }
            int temp = s2.top();s2.pop();
            return temp;
        }

        int front(){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top());s1.pop();
                }
            }
            return s2.top();
        }

        int size(){
            return s1.size()+s2.size();
        }
};

int main(){
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
}