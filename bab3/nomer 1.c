#include <stdio.h>

// Prototipe fungsi
int ganjil(int bilangan);

int main() {
    int input;

    // Meminta input dari pengguna
    printf("Masukkan sebuah bilangan bulat: ");
    scanf("%d", &input);

    // Memanggil fungsi ganjil() untuk menentukan ganjil/genap
    int hasil = ganjil(input);

    // Menampilkan pesan sesuai hasil
    if (hasil == 1) {
        printf("Bilangan ini adalah ganjil.\n");
    } else {
        printf("Bilangan ini bukan ganjil.\n");
    }

    return 0;
}

// Implementasi fungsi ganjil()
int ganjil(int bilangan) {
    // Mengecek apakah bilangan ganjil atau bukan
    if (bilangan % 2 != 0) {
        return 1; // Bilangan ganjil
    } else {
        return 0; // Bukan bilangan ganjil
    }
}
