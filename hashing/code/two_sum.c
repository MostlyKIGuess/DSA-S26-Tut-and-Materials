#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10000

typedef struct Entry {
    int key;
    int value;
    struct Entry *next;
} Entry;

Entry *hashTable[HASH_SIZE];

int hash(int key) {
    int hash = abs(key) % HASH_SIZE;
    return hash < 0 ? hash + HASH_SIZE : hash;
}

void put(int key, int value) {
    int h = hash(key);
    Entry *entry = hashTable[h];

    while (entry != NULL) {
        if (entry->key == key) {
            entry->value = value;
            return;
        }
        entry = entry->next;
    }

    Entry *newEntry = malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = hashTable[h];
    hashTable[h] = newEntry;
}

int get(int key) {
    int h = hash(key);
    Entry *entry = hashTable[h];

    while (entry != NULL) {
        if (entry->key == key)
            return entry->value;
        entry = entry->next;
    }
    return -1;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    for (int i = 0; i < HASH_SIZE; i++)
        hashTable[i] = NULL;

    int *result = malloc(2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int idx = get(complement);

        if (idx != -1) {
            result[0] = idx;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        put(nums[i], i);
    }

    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;

    int *result = twoSum(nums, 4, target, &returnSize);

    if (returnSize == 2) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        printf("Values: [%d, %d]\n", nums[result[0]], nums[result[1]]);
    }

    free(result);

    for (int i = 0; i < HASH_SIZE; i++) {
        Entry *entry = hashTable[i];
        while (entry != NULL) {
            Entry *temp = entry;
            entry = entry->next;
            free(temp);
        }
    }

    return 0;
}
