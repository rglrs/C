#include <stdio.h>

// Prototipe fungsi prima
int prima(int bilangan);

int main() {
    int bilangan;

    // Meminta input bilangan dari pengguna
    printf("Masukkan sebuah bilangan bulat positif: ");
    scanf("%d", &bilangan);

    // Memanggil fungsi prima dan menampilkan hasilnya
    int hasil = prima(bilangan);
    if (hasil == 1) {
        printf("%d adalah bilangan prima.\n", bilangan);
    } else {
        printf("%d bukan bilangan prima.\n", bilangan);
    }

    return 0;
}

// Implementasi fungsi prima
int prima(int bilangan) {
    int i;

    // Jika bilangan kurang dari 2, maka bukan bilangan prima
    if (bilangan < 2) {
        return 0;
    }

    // Mengecek apakah bilangan bisa dibagi oleh bilangan lain selain 1 dan dirinya sendiri
    for (i = 2; i <= bilangan / 2; i++) {
        if (bilangan % i == 0) {
            return 0; // Bukan bilangan prima
        }
    }

    return 1; // Bilangan prima
}
