#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  char c;
  scanf("%d %c", &n, &c);

  if (n == 0) {
    printf("0\n");
    return 0;
  }

  int nlevel = sqrt((n + 1) / 2);
  int real_size = 2 * nlevel * nlevel - 1;
  int rest = n - real_size;

  int row_size = (2 * nlevel - 1 + 1);
  int column_size = (2 * nlevel - 1);

  for (int i = 0; i < nlevel; i++) {
  }
  return 0;
}
