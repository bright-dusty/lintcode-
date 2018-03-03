#include <list>
#include <unordered_map>
#include <iostream>

#include <assert.h>

using namespace std;
typedef int key_type, val_type;

class LRUCache {
private:
	list<pair<key_type, val_type>> orders;
	unordered_map<key_type, decltype(orders.begin())> cache;
	int cap;
	int size;
	
public:
    /*
    * @param capacity: An integer
    */LRUCache(int capacity) : cap(capacity), size(0){
        // do intialization if necessary
		assert(cap);
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
		auto iter = cache.find(key);
		return get(iter);
    }
	
	int get(decltype(cache.begin()) iter) {
		if (iter == cache.end())
			return -1;
		auto item = *iter->second;
		orders.erase(iter->second);
		orders.push_front(item);
		iter->second = orders.begin();
		return item.second;
	}

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
		auto iter = cache.find(key);
		if (iter != cache.end()) {
			iter->second->second = value;
			get(iter);
			return ;
		}
		if (size == cap) {
			auto last_item = orders.back();
			cache.erase(last_item.first);
			orders.pop_back();
			size -- ;
		}
		pair<key_type, val_type> item = {key, value};
		orders.push_front(item);
		cache[key] = orders.begin();
		size ++ ;
    }
};

int main () {
	#define expr(expression) cout << #expression << endl; expression;
	#define print(expr) cout << #expr << " " << (expr) << endl;
	
	LRUCache cache(1101);
	
	#define get(key) print(cache.get(key));
	#define set(key, val) expr(cache.set(key, val));



#include "5.in"

}
