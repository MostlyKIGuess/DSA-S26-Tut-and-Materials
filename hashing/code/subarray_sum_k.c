#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10007

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} Entry;

int subarraySum(int *nums, int numsSize, int k) {
    Entry *table[HASH_SIZE] = {0};

    // insert prefix sum 0 with count 1 (empty subarray)
    int h0 = 0 % HASH_SIZE;
    Entry *init = malloc(sizeof(Entry));
    init->key   = 0;
    init->value = 1;
    init->next  = table[h0];
    table[h0]   = init;

    int prefix = 0, count = 0;
    for (int i = 0; i < numsSize; i++) {
        prefix += nums[i];

        int need = prefix - k;
        // int lookuphash   = need % HASH_SIZE;
        int lookuphash = (need % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
        for (Entry *e = table[lookuphash]; e != NULL; e = e->next) {
            if (e->key == need) {
                count += e->value;
                break;
            }
        }

        // int prefixhash = prefix % HASH_SIZE;
        int prefixhash = (prefix % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
        Entry *found = NULL;
        for (Entry *e = table[prefixhash]; e != NULL; e = e->next) {
            if (e->key == prefix) {
                found = e;
                break;
            }
        }
        if (found) {
            found->value++;
        } else {
            Entry *ne = malloc(sizeof(Entry));
            ne->key   = prefix;
            ne->value = 1;
            ne->next  = table[prefixhash];
            table[prefixhash] = ne;
        }
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        Entry *e = table[i];
        while (e != NULL) {
            Entry *tmp = e;
            e = e->next;
            free(tmp);
        }
    }

    return count;
}

int main() {
    int a1[] = {1, 1, 1};
    printf("Test 1: %d (expected 2)\n", subarraySum(a1, 3, 2));

    int a2[] = {3, 4, 7, 2, -3, 1, 4, 2};
    printf("Test 2: %d (expected 4)\n", subarraySum(a2, 8, 7));

    int a3[] = {3};
    printf("Test 3: %d (expected 1)\n", subarraySum(a3, 1, 3));

    int a4[] = {1, 2, 3};
    printf("Test 4: %d (expected 0)\n", subarraySum(a4, 3, 7));

    int a5[] = {0, 0, 0, 0};
    printf("Test 5: %d (expected 10)\n", subarraySum(a5, 4, 0));

    return 0;
}
