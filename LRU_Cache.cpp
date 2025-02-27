#include <bits/stdc++.h>
using namespace std;


/*
 *  hashing nodes to get O(1) lookup, puting, getting
 *  -------------------------------------------------
 *                      -------
 *                      | key |
 *                      -------
 *                         |
 *                         |
 *                         |
 *              ----------------------
 *              | prev |  val | next |
 *              ----------------------
 *
 *  -How to map linked list nodes ? iterators, O(1) lookUp.
 *  -How erase nodes from linked list ? since iterators or list's nodes pointers 
 *  are mapped into hashMap and erasing in hashMap is fast, so its O(1) removing. 
 *  
 *  -How to put in linked list fast ?
 *      list.push_front() make it O(1) insertion.
 *
 *  -Ordered or Usage :
 *      managed by every time u get(k), put(k) 
 *      it will
 *
 *      instead of moving the last usage in double linked list from the old position to tail and removing the head, O(n) and O(1).
 *      keep pushing to head/front and remove the tail, O(1) and O(1) 
 *
 *      1 remove the last node with key `k`.
 *      2 make new node with key `k` and same value or new value get, put.
 *      3 push that new node to begging of list to ensure O(1) insertion. 
 *      4 map the key `k` to the new made node. 
 *
 * */



class LRUCache {
    public:
        int cap;
        list<pair<int,int>> lruList;
        unordered_map<int, list<pair<int,int>>::iterator> lruMap;

        LRUCache(int capacity) : cap(capacity){
        }
        
        int get(int key) {
            if (lruMap.find(key) == lruMap.end()) return -1;
            else {
                auto node = lruMap[key];
                int val = node->second;
                
                lruList.erase(node);
                lruList.push_front({key, val});

                lruMap[key] = lruList.begin(); //map it back!

                return val;
            }
        }
        
        void put(int key, int value) {
            if(lruMap.find(key) != lruMap.end()) {
                lruList.erase(lruMap[key]);
            } 
            else {
                if (lruList.size() == cap) {
                    int k = lruList.back().first;

                    lruList.pop_back();
                    lruMap.erase(k);
                }
            }

            lruList.push_front({key, value});
            lruMap[key] = lruList.begin();
        }
};











int main() {
    LRUCache mylrucache(2);

    mylrucache.put(1, 1);
    mylrucache.put(2, 2);
    mylrucache.put(3, 3);

    int ans = mylrucache.get(1);

    cout << ans << endl;

    return 0;
}
