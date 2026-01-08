#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int value;
  int index;
} Pair;

int compare(const void *a, const void *b) {
  return ((Pair *)a)->value - ((Pair *)b)->value;
}

int main() {
  int n, target;
  scanf("%d %d", &n, &target);

  Pair *arr = (Pair *)malloc(n * sizeof(Pair));
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i].value);
    arr[i].index = i + 1;
  }

  qsort(arr, n, sizeof(Pair), compare);

  int left = 0, right = n - 1;
  while (left < right) {
    int sum = arr[left].value + arr[right].value;
    if (sum == target) {
      printf("%d %d\n", arr[left].index, arr[right].index);
      free(arr);
      return 0;
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }

  printf("IMPOSSIBLE\n");
  free(arr);
  return 0;
}
