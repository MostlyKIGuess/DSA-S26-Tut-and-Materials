#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 10007

typedef struct Entry {
    int key;
    struct Entry *next;
} Entry;

int longestConsecutive(int *nums, int numsSize) {
    Entry *set[HASH_SIZE] = {0};

    for (int i = 0; i < numsSize; i++) {
        int h = (nums[i] % HASH_SIZE + HASH_SIZE) % HASH_SIZE
        int found = 0;
        for (Entry *e = set[h]; e != NULL; e = e->next)
            if (e->key == nums[i]) { found = 1; break; }
        if (!found) {
            Entry *ne = malloc(sizeof(Entry));
            ne->key  = nums[i];
            ne->next = set[h];
            set[h]   = ne;
        }
    }

    int has(int val) {
        int h = (nums[i] % HASH_SIZE + HASH_SIZE) % HASH_SIZE
        for (Entry *e = set[h]; e != NULL; e = e->next)
            if (e->key == val) return 1;
        return 0;
    }

    int max_len = 0;
    for (int i = 0; i < numsSize; i++) {
        if (has(nums[i] - 1)) continue;

        int curr = nums[i], len = 1;
        while (has(curr + 1)) { curr++; len++; }
        if (len > max_len) max_len = len;
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        Entry *e = set[i];
        while (e != NULL) {
            Entry *tmp = e;
            e = e->next;
            free(tmp);
        }
    }

    return max_len;
}

int main() {
    int a1[] = {100, 4, 200, 1, 3, 2};
    printf("Test 1: %d (expected 4)\n", longestConsecutive(a1, 6));

    int a2[] = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    printf("Test 2: %d (expected 9)\n", longestConsecutive(a2, 10));

    int a3[] = {1};
    printf("Test 3: %d (expected 1)\n", longestConsecutive(a3, 1));

    int a4[] = {5, 5, 5};
    printf("Test 4: %d (expected 1)\n", longestConsecutive(a4, 3));

    int a5[] = {-3, -2, -1, 0, 1};
    printf("Test 5: %d (expected 5)\n", longestConsecutive(a5, 5));

    return 0;
}

/*
Walkthrough (Test 1): nums = [100, 4, 200, 1, 3, 2]
  After building set: {100, 4, 200, 1, 3, 2}

  i=0: nums[0]=100, contains(99)?  No  -> start streak: 100, contains(101)? No -> len=1
  i=1: nums[1]=4,   contains(3)?   Yes -> skip (not a sequence start)
  i=2: nums[2]=200, contains(199)? No  -> start streak: 200, contains(201)? No -> len=1
  i=3: nums[3]=1,   contains(0)?   No  -> start streak: 1,2,3,4 -> len=4
  i=4: nums[4]=3,   contains(2)?   Yes -> skip
  i=5: nums[5]=2,   contains(1)?   Yes -> skip

  best = 4

  Why is this O(n)?
  The inner while loop only runs for sequence *starts*.
  Each number is consumed by exactly one streak, so the
  total work across all while loops is O(n), not O(n^2).

Time:  O(n) average
Space: O(n)
*/
