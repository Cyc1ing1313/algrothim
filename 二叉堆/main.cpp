#include<vector>
#include<iostream>
using namespace std;
class MyHeap{
    private:
        int arr[20];
        int n = 0;

        void swim(int index){
            while(index>1&&arr[index]>arr[index/2]){
                swap(index,index/2);
                index = index/2;
            }
        }

        void swap(int a,int b){
            int temp = arr[a];
            arr[a] = arr[b];
            arr[b] = temp;
        }

        void sink(int index){
            while(2*index+1 <= n){
                int left = 2*index+1;
                if(left+1<=n&&arr[left+1]>arr[left]){
                    left = left+1;
                }
                if(arr[left]<index){
                    break;
                }
                swap(left,index);
                index = left;
            }

        }
    public:
        void insert(int key){
            n++;
            arr[n] = key;
            swim(n);
        }

        int pop(){
            int ret = arr[1];
            swap(1,n);
            arr[n] = 0;
            n--;
            sink(1);
            return ret;
        }

};


int main(){
    MyHeap heap;
    heap.insert(1);
    heap.insert(4);
    heap.insert(100);
    cout<<heap.pop()<<endl;
    cout<<heap.pop()<<endl;
    cout<<heap.pop()<<endl;
    cout<<heap.pop()<<endl;
    cout<<heap.pop()<<endl;
}