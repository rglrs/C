#include <stdio.h>

int main() {
    int n;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            printf("%d ", i);
        } else {
            printf("%d ", -i);
        }
    }

    printf("\n");

    return 0;
}