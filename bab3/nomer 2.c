#include <stdio.h>

// Prototipe fungsi faktorial
int faktorial(int n);

int main() {
    int bilangan;

    // Meminta input bilangan dari pengguna
    printf("Masukkan bilangan untuk menghitung faktorial: ");
    scanf("%d", &bilangan);

    // Memanggil fungsi faktorial dan menampilkan hasilnya
    int hasil = faktorial(bilangan);
    printf("Faktorial dari %d adalah %ld\n", bilangan, hasil);

    return 0;
}

// Implementasi fungsi faktorial
int faktorial(int n) {
    if (n == 0) {
        return 1; // Faktorial dari 0 adalah 1
    } else {
        int hasil = 1;
        for (int i = 1; i <= n; i++) {
            hasil *= i;
        }
        return hasil;
    }
}
