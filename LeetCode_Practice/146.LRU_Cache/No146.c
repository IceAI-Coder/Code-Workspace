// https://leetcode.com/problems/lru-cache/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_HASH_SIZE 10001

typedef struct HASH_ELEMENT{
    bool used;
    int value;
    int prevKey;
    int nextKey;
} HASH_ELEMENT;

typedef struct LRUCache{
    int capacity;
    int size;
    int headKey;
    int lastKey;
    HASH_ELEMENT *hashTable;
} LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache *output = (LRUCache*)malloc(sizeof(LRUCache));
    output->capacity = capacity;
    output->size = 0;
    output->headKey = -1;
    output->lastKey = -1;
    output->hashTable = (HASH_ELEMENT*)calloc(MAX_HASH_SIZE, sizeof(HASH_ELEMENT));
    return output;
}

void remove_LeastRecentlyUsed(LRUCache *obj){
    if(obj->size <= 0){
        return;
    }   
    
    obj->size --;
    int key = obj->lastKey;
    if(obj->size == 0){
        obj->headKey = -1;
        obj->lastKey = -1;
    }
    else{
        obj->lastKey = obj->hashTable[key].prevKey;
        obj->hashTable[obj->lastKey].nextKey = -1;
    }
    obj->hashTable[key].used = false;
    obj->hashTable[key].nextKey = -1;
    obj->hashTable[key].prevKey = -1;
}

void update_LatestUsed(LRUCache *obj, int key){
    if(obj->headKey == key){
        return;
    }

    if(obj->lastKey == key){
        // remove from tail
        obj->lastKey = obj->hashTable[key].prevKey;
        obj->hashTable[obj->lastKey].nextKey = -1;
    }
    else{
        // remove from middle
        obj->hashTable[obj->hashTable[key].prevKey].nextKey = obj->hashTable[key].nextKey;
        obj->hashTable[obj->hashTable[key].nextKey].prevKey = obj->hashTable[key].prevKey;
    }

    // add to front
    obj->hashTable[key].nextKey = obj->headKey;
    obj->hashTable[key].prevKey = -1;
    obj->hashTable[obj->headKey].prevKey = key;
    obj->headKey = key;
}

int lRUCacheGet(LRUCache* obj, int key) {
    if(obj->hashTable[key].used){
        update_LatestUsed(obj, key);
        return obj->hashTable[key].value;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(obj->hashTable[key].used){
        obj->hashTable[key].value = value;
        update_LatestUsed(obj, key);
        return;
    }

    if(obj->size == obj->capacity){
        remove_LeastRecentlyUsed(obj);
    }

    obj->hashTable[key].used = true;
    obj->hashTable[key].value = value;
    obj->hashTable[key].prevKey = -1;
    obj->hashTable[key].nextKey = obj->headKey;

    if(obj->headKey != -1){
        obj->hashTable[obj->headKey].prevKey = key;
    }
    obj->headKey = key;
    if(obj->size==0){
        obj->lastKey = key;
    }
    obj->size++;
}

void lRUCacheFree(LRUCache* obj) {
    free(obj->hashTable);
    free(obj);
}


void printLRUCache(LRUCache *obj){
    if(obj->headKey == -1){
        printf("{null}\n");
        return;
    }

    int currKey = obj->headKey;
    printf("{");
    while(currKey != -1){
        printf("%d=%d, ", currKey, obj->hashTable[currKey].value);
        currKey = obj->hashTable[currKey].nextKey;
    }
    printf("}\n");


}
/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/

int main(){
    LRUCache *obj = lRUCacheCreate(2);
    lRUCachePut(obj, 1, 1);
    lRUCachePut(obj, 2, 2);
    lRUCacheGet(obj, 1);
    lRUCachePut(obj, 3, 3);
    lRUCacheGet(obj, 2);
    lRUCachePut(obj, 4, 4);
    lRUCacheGet(obj, 1);
    lRUCacheGet(obj, 3);
    lRUCacheGet(obj, 4);
    lRUCacheFree(obj);    
    return 0;
}