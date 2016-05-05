#include <iostream>
#include <string>
#include <map>
#include <assert.h>
#include <tr1/unordered_map>
using namespace std::tr1;
using namespace std;

struct Node{
    int key;
    int value;
    Node* last;
    Node* next;
    Node(int k, int v){key=k; value=v; last=NULL; next=NULL;}
};

class LRUCache{
private:
    int cache_capacity;
    unordered_map<int, Node*> key_value_map;
    Node *head;

    void move_to_tail(Node* node){
        if(node == head){
            head = head->next;
        }
        else if(node != head->last){
            node->last->next = node->next;
            node->next->last = node->last;
            head->last->next = node;
            node->last = head->last;
            node->next = head;
            head->last = node;
        }
    }
    inline void insert_into_list(Node* node){
        if(head == NULL){
            node->next = node->last = node;
            head = node;
        }
        else{
            Node* tail = head->last;
            node->last = tail;
            tail->next = node;
            node->next = head;
            head->last = node;
        }
    }
public:
    LRUCache(int capacity) {
        cache_capacity = capacity;
        head = NULL;
    }
    
    int get(int key) {
        auto it = key_value_map.find(key);
        int val;
        if(it == key_value_map.end()) // cant find key in map
            val = -1;
        else {
            Node* node = it->second;
            val = node->value;
            move_to_tail(node);
        }
        return val;
    }
    
    void set(int key, int value) {
        auto it = key_value_map.find(key);
        if(it != key_value_map.end()){ // find key in map
            move_to_tail(it->second);
            it->second->value = value;
            return;
        }
        // key not in the map
        // map is full
        if(key_value_map.size() >= cache_capacity) {
            // find lru
            if(head == NULL)    // capacity is 0
                return;
            key_value_map.erase(head->key);
            // rewrite
            head->value = value;
            head->key = key;
            key_value_map[key] = head;
            move_to_tail(head);
        }
        else{
            Node* new_node = new Node(key, value);
            insert_into_list(new_node);
            key_value_map[key] = new_node;
        }
    }
    ~LRUCache() {
        if(head!=NULL){
            Node* tmp = head->next;
            delete head;
            while(tmp != head){
                Node* tmp2 = tmp;
                tmp = tmp->next;
                delete tmp2;
            }
        }
    }
};


int main(int argc, char *argv[])
{
    LRUCache cache(2048);
    for (int i=0; i<50000; ++i)
    {
        cache.set(i, i*10);
        if(i>3000)
            cache.get(i-3000);
    }
    return 0;
}
