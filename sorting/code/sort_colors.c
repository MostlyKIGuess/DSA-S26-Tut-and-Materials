#include <stdio.h>
#include <stdlib.h>

void sortColors(int *nums, int numsSize) {
  int low = 0, mid = 0, high = numsSize - 1;

  while (mid <= high) {
    if (nums[mid] == 0) {
      int temp = nums[low];
      nums[low] = nums[mid];
      nums[mid] = temp;
      low++;
      mid++;
    } else if (nums[mid] == 1) {
      mid++;
    } else {
      int temp = nums[mid];
      nums[mid] = nums[high];
      nums[high] = temp;
      high--;
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int *nums = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }

  sortColors(nums, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  // Ideally I as a good person should free nums, but I won't
  return 0;
}
