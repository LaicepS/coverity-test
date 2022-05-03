#include <string.h>
#include <stdlib.h>
#include <limits.h>

void* private_mempcy(void * dst, const void * src, size_t n) {
  return memcpy(dst, src, n);
}

void test_memcpy() {
  int a[10];
  memset(a, 0, sizeof(a));
  private_mempcy(a, a, sizeof(a));
}

void test_outside_object() {
  int tab[1];
  size_t len = sizeof(tab);
  memset(tab, 0, len);

  int * left, *right;
  left = &tab[0];
  right = &tab[len-1];

  while(left <= right) {
    left++;
    right--;
  }
}

int abs(int val) {
  return val < 0 ? -val : val;
}

void test_signed_overflow() {
  int a = abs(INT_MIN);
  (void)a;
}

int main() {
  test_memcpy();
  test_outside_object();
  test_signed_overflow();
  return 0;
}
