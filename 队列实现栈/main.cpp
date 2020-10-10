#include<queue>
using namespace std;

class MyStack{
    private:
        queue<int> q;
        int top_elem = 0;
    public:
        void push(int x){
            q.push(x);
            top_elem = x;
        }

        int pop(){
            int size = q.size();
            while(size>2){
                q.push(q.front());
                q.pop();
                size--;
            }
            top_elem = q.front();
            q.push(q.front());q.pop();
            int temp = q.front();q.pop();
            return temp;
        }

        int top(){
            return top_elem;
        }

        bool empty(){
            return q.size() == 0;
        }
};