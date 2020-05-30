//
// Created by Vigo Wong on 28/5/20.
//


//get(key) - Get the value (will always be positive) of the key
// if the key exists in the cache, otherwise return -1.

//put(key, value) - Set or insert the value
// if the key is not already present.
// When the cache reached its capacity,
// it should invalidate the least recently used item
// before inserting a new item.

#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if(iter.find(key)!=iter.end()){
            // if the key is found in the LRU, then it's placed at the head of the list
            put(key, iter[key]->second);
            return iter[key]->second;
        }else return -1;
    }

    void put(int key, int value) {
        if(iter.find(key)!=iter.end())
            recent.erase(iter[key]);
        else if (recent.size()>= capacity){
            iter.erase(recent.back().first);
            recent.pop_back();
        }
        recent.push_front({key, value});
        iter[key] = recent.begin();
    }

private:
    int capacity;
    list<pair<int, int>> recent;
    unordered_map<int, list<pair<int, int>>::iterator> iter;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */