#include <map>
#include <list>
#include <vector>
#include <iostream>

#include <assert.h>

using namespace std;
typedef int key_type, val_type, freq_type;

struct map_val_type {
    val_type val;
    freq_type freq;
    list<key_type>::iterator iter;
};

typedef map<key_type, map_val_type> map_type;
typedef map<freq_type, list<key_type>> freq_map_type;

class LFUCache {
public:
    /*
    * @param capacity: An integer
    */LFUCache(int capacity) :capacity(capacity), size(0)
    {
        // do intialization if necessary
        assert(capacity);
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(key_type key, val_type value) {
        // write your code here
        auto iter = map.find(key);
        if (iter != map.end()) {
            iter->second.val = value;
            get(key, iter);
            return ;
        } 
        if (size == capacity) {
            key_type pop_key = freq_map.begin()->second.back();
            freq_map.begin()->second.pop_back();
            if (freq_map.begin()->second.empty())
                freq_map.erase(freq_map.begin());
            map.erase(pop_key);
            size -- ;
        }
        auto freq_map_iter = freq_map.find(1);
        if (freq_map_iter == freq_map.end())
            freq_map[1] = {key};
        else freq_map_iter->second.push_front(key);
        map_val_type val = {value, 1, freq_map.find(1)->second.begin()};
        map[key] = val;
        size ++ ;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    val_type get(key_type key) {
        // write your code here
        auto iter = map.find(key);
        if (iter == map.end())
            return -1;
        return get(key, iter);
    }
    
    val_type get(key_type key, map_type::iterator iter) {
        freq_type &freq = iter->second.freq;
        freq_map[freq].erase(iter->second.iter);
        if (freq_map[freq].empty())
            freq_map.erase(freq);
        freq ++ ;
        auto freq_map_iter = freq_map.find(freq);
        if (freq_map_iter == freq_map.end()) 
            freq_map[freq] = {key};
        else freq_map_iter->second.push_front(key);
        iter->second.iter = freq_map[freq].begin();
        return iter->second.val;
    }
    
    
private:
    int capacity;
    int size ;
    map_type map;
    freq_map_type freq_map;
    
    
};

int main() {

#include "5.in"

}
