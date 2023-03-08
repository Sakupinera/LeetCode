#include <iostream>
#include <vector>
#include <list>
#include <map>
using std::vector;
using std::list;
using std::pair;
/*
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
*/
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        m_size = 1000;
        mp.resize(m_size);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        list<pair<int,int>>& list = mp[key % m_size]; // auto& list = mp[key % m_size];
        for(auto iter = list.begin(); iter != list.end(); iter++) {
            if( iter->first == key ){
                iter->second = value;
                return;
            }
        } list.emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        list<pair<int,int>>& list = mp[key % m_size]; // auto& list = mp[key % m_size];
        for(auto iter = list.begin(); iter != list.end(); iter++) {
            if( iter->first == key ) return iter->second;
        } return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        list<pair<int,int>>& list = mp[key % m_size]; // auto& list = mp[key % m_size];
        for(auto iter = list.begin(); iter != list.end(); iter++) {
            if( iter->first == key ){
                list.erase(iter);
                return;
            }
        }
    }
    
private:
    vector<list<pair<int, int>>> mp;
    size_t m_size;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
int main(){
    return 0;
}