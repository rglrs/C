#include <stdio.h>

// Fungsi untuk menghasilkan deret Fibonacci hingga n
void fibonacci(int n) {
    int a = 0, b = 1, c;
    printf("Deret Fibonacci hingga %d:\n", n);

    if (n >= 1) {
        printf("%d ", a);
    }
    if (n >= 2) {
        printf("%d ", b);
    }

    for (int i = 3; i <= n; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }

    printf("\n");
}

int main() {
    int bilangan;

    // Meminta pengguna memasukkan bilangan
    printf("Masukkan sebuah bilangan: ");
    scanf("%d", &bilangan);

    if (bilangan < 1) {
        printf("Masukkan bilangan positif yang lebih besar dari 0.\n");
    } else {
        fibonacci(bilangan);
    }

    return 0;
}
