#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void test_memcpy() {
  int a[10];
  int * b = a;
  memset(a, 0, sizeof(a));
  int * res = (int* ) memcpy(b, a, sizeof(a));

  printf("memcpy success ? %d\n", res > a);
}

void test_outside_object() {
  int * tab = (int*) malloc(sizeof(int));
  if (!tab)
    return;
  size_t len = 1;
  memset(tab, 0, len*sizeof(int));

  int * left, *right;
  left = &tab[0];
  right = &tab[len-1];
  int loop_count = 0;

  while(left <= right) {
    loop_count++;
    left++;
    right--;
  }

  printf("Loop count %d\n", loop_count);

  free(tab);
}

int abs(int val) {
  return val < 0 ? -val : val;
}

void test_signed_overflow() {
  int a = abs(INT_MIN);
  printf("%d\n", a);
}

int main() {
  test_memcpy();
  test_outside_object();
  test_signed_overflow();
  return 0;
}
