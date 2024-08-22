#include <stdio.h>

#define MAKS 100 // Ukuran maksimum array

int main() {
    int n;
    int array[MAKS];

    // Meminta pengguna memasukkan jumlah elemen array
    printf("Masukkan jumlah elemen array (<= %d): ", MAKS);
    scanf("%d", &n);

    if (n <= 0 || n > MAKS) {
        printf("Jumlah elemen tidak valid. Harus lebih dari 0 dan tidak lebih dari %d.\n", MAKS);
        return 1; // Keluar program dengan kode error
    }

    // Meminta pengguna memasukkan elemen-elemen array
    printf("Masukkan %d elemen integer:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemen ke-%d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Mencari nilai terbesar dalam array
    int nilaiTerbesar = array[0]; // Menginisialisasi nilaiTerbesar dengan elemen pertama
    for (int i = 1; i < n; i++) {
        if (array[i] > nilaiTerbesar) {
            nilaiTerbesar = array[i];
        }
    }

    // Menampilkan nilai terbesar dalam array
    printf("Nilai terbesar dalam array adalah: %d\n", nilaiTerbesar);

    return 0;
}
