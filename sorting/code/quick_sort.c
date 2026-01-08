#include <stdio.h>

// int call = 0;
int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  int temp = arr[i + 1];
  arr[i + 1] = arr[high];
  arr[high] = temp;

  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  // call++;
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  int arr[] = {3, 2, 4, 5, 1, 7, 6};
  // int arr[] = {1, 2, 3, 4, 5, 6, 7,};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Original: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  quickSort(arr, 0, n - 1);

  printf("Sorted: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  // printf("%d Total Calls\n", call);

  return 0;
}
