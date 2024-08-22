#include <stdio.h>

int faktorial(int n) {
  return n;
}

main()
{
  int n,hasil;
  printf("Masukkan bilangan : ");
  scanf("%d", &n);
    hasil = 1;
  for(int i = 1; i <= n; i++) {
    hasil = hasil * i;
  }

  int m = faktorial(hasil);
  printf("%d", m);
}