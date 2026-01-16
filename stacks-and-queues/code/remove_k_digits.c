#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100005

char *removeKdigits(char *num, int k) {
  int len = strlen(num);
  if (k == 0)
    return num;
  if (k >= len)
    return "0";

  char *stack = (char *)malloc(len + 1);
  int top = -1;

  for (int i = 0; i < len; i++) {
    while (k > 0 && top >= 0 && stack[top] > num[i]) {
      top--;
      k--;
    }
    stack[++top] = num[i];
  }

  while (k > 0) {
    top--;
    k--;
  }

  stack[top + 1] = '\0';

  int start = 0;
  while (stack[start] == '0' && start < top)
    start++;

  if (start > top)
    return "0";

  char *result = (char *)malloc(top - start + 2);
  strcpy(result, stack + start);
  free(stack);
  return result;
}

int main() {
  char num[MAX_SIZE];
  int k;
  scanf("%s %d", num, &k);

  char *result = removeKdigits(num, k);
  printf("%s\n", result);

  return 0;
}
