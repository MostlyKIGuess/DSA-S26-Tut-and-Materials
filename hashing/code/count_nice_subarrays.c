#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numberOfSubarrays(int *nums, int n, int k) {
    int *map = calloc(n + 1, sizeof(int));
    map[0] = 1;

    int prefix = 0, count = 0;
    for (int i = 0; i < n; i++) {
        prefix += nums[i] % 2;
        if (prefix - k >= 0)
            count += map[prefix - k];
        map[prefix]++;
    }

    return count;
}

int main() {
    int a1[] = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    printf("Test 1: %d (expected 16)\n", numberOfSubarrays(a1, 10, 2));

    int a2[] = {1, 1, 2, 1, 1};
    printf("Test 2: %d (expected 2)\n", numberOfSubarrays(a2, 5, 3));

    int a3[] = {2, 4, 6};
    printf("Test 3: %d (expected 0)\n", numberOfSubarrays(a3, 3, 1));

    int a4[] = {1, 1, 1, 1, 1};
    printf("Test 4: %d (expected 3)\n", numberOfSubarrays(a4, 5, 3));

    int a5[] = {2, 4, 1, 6};
    printf("Test 5: %d (expected 4)\n", numberOfSubarrays(a5, 4, 0));

    return 0;
}
