#include<unordered_map>
#include<list>
using namespace std;
class LRUCache{
    unordered_map<int,list<pair<int,int>>::iterator> map;
    list<pair<int,int>> cache;
    int capacity;

    public:
        int get(int key){
            if(map.find(key) == map.end()){
                return -1;
            }
            int val = map[key]->second;
            return val;
        }

        void put(int key,int val){
            pair<int,int> x = {key,val};
            if(map.find(key) != map.end()){
                cache.erase(map[key]);
                cache.emplace_front(x);
                map[key] = cache.begin();
            }else{
                if(capacity == cache.size()){
                    pair<int,int> last = cache.back();cache.pop_back();
                    map.erase(last.first);
                }
                cache.emplace_front(x);
                map[key] = cache.begin();
            }
        }
};