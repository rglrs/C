#include <stdio.h>

int main() {
    int n, triangular = 0;

    printf("Masukkan bilangan: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        triangular += i;
    }

    printf("Bilangan triangular dari %d adalah: %d\n", n, triangular);

    return 0;
}