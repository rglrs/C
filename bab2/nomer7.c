#include <stdio.h>

int main() {
    int n;
    int faktorial = 1;

    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Faktorial tidak untuk bilangan negatif\n");
    } else {
        for (int i = 1; i <= n; i++) {
            faktorial *= i;
        }

        printf("%d! = %d\n", n, faktorial);
    }

    return 0;
}