#include <iostream>
#include <vector>
using std::vector;
/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
*/
class MyHashSet {
public:
    /** Initialize your data structure here. */
    int capacity;
    int size;
    vector<int> s;
    float load_factor;
    
    MyHashSet() {
        capacity = 8;
        size = 0;
        //-1 means untouched
        //-2 means once exist but removed, tombstone
        s = vector<int>(capacity, -1);
        load_factor = 2.0f/3.0f;
    }
    
    int hash(int key){
        return key % capacity;
    }
    
    int rehash(int key){
        return (key*5+1) % capacity;
    }
    
    void add(int key) {
        //enlarge the vector
        if(float(size)/capacity >= load_factor){
            capacity <<= 1;
            vector<int> ns(capacity, -1);
            
            for(int i = 0; i < capacity >> 1; ++i){
                if(s[i] >= 0){ //not -1 or -2
                    int pos = hash(s[i]);
                    while(ns[pos] != -1){ //while the position is filled
                        //when rehash, we use the "new capacity"!!
                        pos = rehash(pos);
                    }
                    //find a empty place, fill it
                    ns[pos] = s[i];
                }
            }
            
            s = ns;
        }
        
        int pos = hash(key);
        
        while(s[pos] >= 0){ //want to find s[pos] is -1 or -2
            //key is already in the hashset
            if(s[pos] == key) return;
            pos = rehash(pos);
        }
        
        //found an empty space, fill it
        s[pos] = key;
        ++size;
    }
    
    void remove(int key) {
        int pos = hash(key);
        
        /*
        loop until we meet an untouched position,
        note that we don't stop when we meet -2(tombstone)
        */
        while(s[pos] != -1){ 
            if(s[pos] == key){
                //only remove if we meet "key"
                s[pos] = -2;
                --size;
                break;
            }
            pos = rehash(pos);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int pos = hash(key);
        
        /*
        loop until we meet an untouched position,
        note that we don't stop when we meet -2(tombstone)
        */
        while(s[pos] != -1){
            if(s[pos] == key) return true;
            pos = rehash(pos);
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
int main(){

    return 0;
}