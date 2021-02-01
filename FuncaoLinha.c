#include <stdio.h>

int main(void) {
  int i, j, n = 0, a[9] = {1, 0, 3, 0, 5, 0, 7, 8, 0}, b[9] = {0}, n_existe;
  for (j = 1; j < 10; j++) {
    n_existe = 1;
    for (i = 0; i < 9; i++) {
      if (a[i] == j) {
        n_existe = 0;
        break;
      }
    }
    if (n_existe == 1) {
      b[n] = j;
      n++;
    }
  }
  for (i = 0; i < 9; i++)
    printf("%d ", b[i]);
}
